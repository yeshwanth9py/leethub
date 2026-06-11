// Last updated: 6/11/2026, 11:14:08 AM
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
const int MOD = 1'000'000'007;

// ---------------- Fenwick (BIT) for 1..N ----------------
struct Fenwick {
    int n;
    vector<int> bit;
    Fenwick(int n=0){ init(n); }
    void init(int n_){
        n = n_;
        bit.assign(n+1, 0);
    }
    // add value v at position idx (1-based)
    void add(int idx, int v){
        while(idx <= n){
            bit[idx] = (bit[idx] + v) % MOD;
            idx += idx & -idx;
        }
    }
    // sum of prefix [1..idx]
    int sumPrefix(int idx){
        long long res = 0;
        while(idx > 0){
            res += bit[idx];
            idx -= idx & -idx;
        }
        return (int)(res % MOD);
    }
    // sum of [l..r]
    int sumRange(int l, int r){
        if(r < l) return 0;
        int res = (sumPrefix(r) - sumPrefix(l-1)) % MOD;
        if(res < 0) res += MOD;
        return res;
    }
};
// ------------------------------------------------------

// Linear sieve to compute Möbius mu[1..maxN]
vector<int> mobius_linear_sieve(int maxN){
    vector<int> mu(maxN+1, 0);
    vector<int> primes;
    vector<int> least(maxN+1, 0);
    mu[1] = 1;
    for(int i = 2; i <= maxN; ++i){
        if(least[i] == 0){
            least[i] = i;
            primes.push_back(i);
            mu[i] = -1;
        }
        for(int p : primes){
            long long v = 1LL * p * i;
            if(v > maxN) break;
            least[v] = p;
            if(i % p == 0){
                mu[v] = 0;
                break;
            } else {
                mu[v] = -mu[i];
            }
        }
    }
    return mu;
}

class Solution {
public:
    int totalBeauty(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;

        int maxA = 0;
        for(int x : nums) if(x > maxA) maxA = x;

        // positions[val] = list of indices (0-based) where nums[i] == val
        vector<vector<int>> positions(maxA + 1);
        for(int i = 0; i < n; ++i) positions[nums[i]].push_back(i);

        // mobius function mu[k] for k = 1..maxA
        vector<int> mu = mobius_linear_sieve(maxA);
        mu[1] = 1; // ensure

        // F[d] = number of non-empty strictly increasing subsequences using only elements divisible by d
        vector<int> F(maxA + 1, 0);

        // For each d, gather (index, scaledValue = nums[index]/d) for multiples of d
        for(int d = 1; d <= maxA; ++d){
            vector<pair<int,int>> items; // (original index, scaled value)
            for(int multiple = d; multiple <= maxA; multiple += d){
                if(positions[multiple].empty()) continue;
                int scaledVal = multiple / d;
                for(int pos : positions[multiple]){
                    items.emplace_back(pos, scaledVal);
                }
            }
            if(items.empty()) continue;

            // process in original order (increasing pos) to respect subsequences
            sort(items.begin(), items.end(), [](auto &a, auto &b){ return a.first < b.first; });

            // find max scaled value for Fenwick size
            int maxScaled = 0;
            for(auto &pr : items) if(pr.second > maxScaled) maxScaled = pr.second;
            Fenwick bit(maxScaled + 2); // +2 for safety (1-based indexing)

            long long totalForD = 0;
            // For each item: newSubseqsEndingHere = 1 + sum(counts for values < scaled)
            for(auto &pr : items){
                int scaled = pr.second;
                int lessCount = bit.sumPrefix(scaled - 1); // counts of subsequences ending with value < scaled
                int newCount = ( (long long)1 + lessCount ) % MOD;
                bit.add(scaled, newCount);
                totalForD += newCount;
                if(totalForD >= MOD) totalForD -= MOD;
            }
            F[d] = (int)totalForD;
        }

        // Möbius inversion: G(d) = sum_{k>=1} mu[k] * F[d*k]
        long long answer = 0;
        for(int d = 1; d <= maxA; ++d){
            if(F[d] == 0) { // small opt: still must compute with mu though later when used in G for smaller d; but here skip to save time
                // Can't skip entirely because G for divisors uses F[d*k]. But we'll compute G(d) explicitly below.
            }
            long long Gd = 0;
            for(int k = 1; (long long)d * k <= maxA; ++k){
                if(mu[k] == 0) continue;
                int idx = d * k;
                Gd += 1LL * mu[k] * F[idx];
            }
            Gd %= MOD;
            if(Gd < 0) Gd += MOD;
            answer += ( (long long)d * Gd ) % MOD;
            answer %= MOD;
        }

        return (int)answer;
    }
};
