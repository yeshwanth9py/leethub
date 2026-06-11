// Last updated: 6/11/2026, 11:10:58 AM
class Solution {
public:
    vector<long long> spf;
    void pre(long long mx){
        spf.assign(mx+1, 0);
        for(long long i=1; i<=mx; i++){
            spf[i] = i;
        }
        for(long long i=2; i<=mx; i++){
            if(spf[i] == i){
                for(long long j=1LL*i*i; j<=mx; j+=i){
                    if(spf[j] == j){
                        spf[j] = i;
                    }
                }
            }
        }
    }
    vector<long long> getprimes(long long el){
        vector<long long> temp;
        while(el>1){
            long long cur = spf[el];
            while(el%cur == 0){
                el = el/cur;
            }
            temp.push_back(cur);
        }
        return temp;
    }

    long long maxScore(vector<int>& nums, long long maxVal) {
        long long mx = *max_element(nums.begin(), nums.end());
        mx = max(mx, maxVal);

        unordered_map<long long, long long> freq;
        for(long long el: nums){
            freq[el]++;
        }

        vector<long long> multiples(mx+1, 0);
        long long n = nums.size();

        for(long long i=2; i<=mx; i++){
            long long cnt = 0;
            for(long long j=i; j<=mx; j+=i){
                cnt += freq[j];
            }
            multiples[i] = cnt;
        }

        long long ans = 0;
        pre(mx);

        for(long long v=1; v<=mx; v++){
            vector<long long> primes = getprimes(v);
            long long tot = primes.size();
            long long k = 0;
            for(long long mask=1; mask<(1<<tot); mask++){
                long long prod = 1;
                long long cnt = 0;
                for(long long j=0; j<tot; j++){
                    if((mask&(1<<j)) != 0){
                        prod = prod*primes[j];
                        cnt++;
                    }
                }
                if(cnt%2 == 1){
                    k += multiples[prod];
                }else{
                    k -= multiples[prod];
                }
            }
            if(freq[v]>0){
                if(v == 1){
                    ans = 0;
                }
                long long opr = max(0LL, k-1);
                ans = max(ans, v-(opr));
            }
            if(v>=1 && v<=maxVal){
                long long opr = max(1LL, k);
                ans = max(ans, v-opr);
            }
        }

        return ans;
    }
};