// Last updated: 6/11/2026, 11:21:41 AM
class Solution {
public:
    long long fact[1001000];
    long long ifact[1001000];
    const long long mod = 1e9+7;

    long long binpow(long long x, long long n, long long mod){
        if(n == 0){
            return 1;
        }

        if(n == 1){
            return x;
        }

        long long ans = binpow(x, n/2, mod);
        ans = (ans*ans)%mod;
        if(n&1){
            ans = (ans*x)%mod;
        }

        return ans;
    }

    void pre(){
        fact[0] = fact[1] = 1;
        for(long long i=2; i<1001000; i++){
            fact[i] = (fact[i-1] * i)%mod;
            fact[i] = (fact[i]+mod)%mod;
        }
        
        ifact[1001000-1] = binpow(fact[1001000-1], mod-2, mod);
        for(long long i=1001000-2; i>=0; i--){
            ifact[i] = (ifact[i+1] * (i+1))%mod;
            ifact[i] = (ifact[i]+mod)%mod;
        }
    }

    int countAnagrams(string s) {
        pre();
        vector<string> vec;
        istringstream iss(s);
        string token;
        while(iss>>token){
            vec.push_back(token);
        }

        long long ans = 1;
        for(string temp: vec){
            unordered_map<char, long long> ump;
            for(char ch: temp){
                ump[ch]++;
            }
            long long m = temp.size();
            long long cur = fact[m];
            // cout<<cur<<" ";
            for(auto el: ump){
                cur = cur*(ifact[el.second])%mod;
                cur = (cur+mod)%mod;
                // cout<<el.second<<" ";
            }
            // cout<<cur<<endl;
            ans = (ans*cur)%mod;
        }


        return ans;
    }
};