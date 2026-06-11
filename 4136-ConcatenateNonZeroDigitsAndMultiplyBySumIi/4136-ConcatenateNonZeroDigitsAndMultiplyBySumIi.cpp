// Last updated: 6/11/2026, 11:12:10 AM
class Solution {
public:
    long long mod = 1e9+7;
    long long binpow(long long x, long long n){
        x = x%mod;
        if(n == 0) return 1;
        long long ans = binpow(x, n/2);
        ans = (ans*ans)%mod;
        if(n&1){
            ans = (ans*x)%mod;
        }
        return ans;
    }
    long long getsz(long long num){
        long long l = 0;
        while(num){
            l++;
            num = num/10;
        }
        return l;
    }
    
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        long long n = s.size();
        vector<long long> prefnum(n, 0);
        vector<long long> summ(n, 0);
        vector<int> poss;
        vector<int> cntNonZero(n, 0);            // <<-- ADDED: count non-zero digits up to i
        long long cur = 0;
        long long acc = 0;
        int cnt = 0;
        for(int i=0; i<n; i++){
            int digit = s[i]-'0';
            if(digit == 0){
                prefnum[i] = cur;
            }else{
                poss.push_back(i);
                // <<-- FIX: keep cur modulo mod after adding digit (single-line)
                cur = ( (cur*10) % mod + digit );
                prefnum[i] = cur;   
                cnt++;
            }
            acc += digit;
            summ[i] = acc;
            cntNonZero[i] = cnt;                  // update count
        }
        vector<int> asalas;

        for(auto q: queries){
            int s = q[0];
            int e = q[1];

            auto it = upper_bound(poss.begin(), poss.end(), e);
            if(it == poss.begin()){
                asalas.push_back(0);
                continue;
            }
            it--;
            e = *(it);

            auto it2 = upper_bound(poss.begin(), poss.end(), s-1);
            if(it2 == poss.begin()){
                asalas.push_back((prefnum[e]*(summ[e]))%mod);
                continue;
            }else{
                it2--;
                s = *(it2);   
            }
            
            // <<-- REPLACED: compute exponent from counts of non-zero digits (safe)
            long long ex = (long long)(cntNonZero[e] - ( (s==-1)?0:cntNonZero[s] ));

            long long lasttp = (prefnum[e] - (((s==-1)?0:prefnum[s])*(binpow(10, ex))%mod) +mod)%mod;
            long long lastsm = summ[e] - ((s==-1)?0:summ[s]);

            long long ans = (lasttp*lastsm)%mod;
            asalas.push_back((int)ans);
        }

        return asalas;
    }
};
