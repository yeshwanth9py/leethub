// Last updated: 6/11/2026, 11:12:43 AM
class Solution {
public:
    // vector<bool> isprime;
    // void pre(){
    //     isprime.resize(1e9+5, 1);
    //     isprime[0] = 0;
    //     isprime[1] = 0;
    //     for(long long i=2; i<1e9+5; i++){
    //         if(isprime[i] == 1){
    //             for(long long j=i*i; j<1e9+5; j=j+i){
    //                 isprime[j] = 0;
    //             }
    //         }
    //     }
    // }
    bool isprime(long long num){
        if(num == 1) return 0;
        for(long long i=2; i*i<=num; i++){
            if(num%i == 0) return 0;
        }
        return 1;
    }
    bool completePrime(int num) {
        // pre();
        string s = to_string(num);
        long long pref=0;
        for(long long i=0; i<s.size(); i++){
            pref = (pref*10) + (s[i]-'0');
            if(isprime(pref) == 0) return 0;
        }

        reverse(s.begin(), s.end());
        pref = 0;
        int mu = 0;
        for(long long i=0; i<s.size(); i++){
            pref = pref + (s[i]-'0')*pow(10, mu);
            // cout<<pref<<" ";
            if(isprime(pref) == 0) return 0;
            mu++;
        }

        return 1;
        
    }
};



