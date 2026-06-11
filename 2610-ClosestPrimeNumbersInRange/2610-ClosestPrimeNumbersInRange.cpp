// Last updated: 6/11/2026, 11:21:40 AM
using ll = long long;
class Solution {
public:
    vector<int> isprime;
    void sieveoferathos(){
        isprime[1]=isprime[0] = 0;
        isprime[2] = 1;
        for(ll i=2; i*i<=1000000; i++){
            if(isprime[i]){
                for(ll j=i*i; j<=1000000; j=j+i){
                    isprime[j] = 0;
                }
            }
        }
    }
    Solution(){
        isprime.resize(10000000, 1);
        sieveoferathos();
    }

    vector<int> closestPrimes(int left, int right) {
        ll mindif = 1e11;
        ll num1 = -1;
        ll num2 = -1;
        ll prevprime = -1;
        for(ll i=left; i<=right; i++){
            if(isprime[i]){
                if(prevprime != -1){
                    if(i-prevprime <mindif){
                        mindif = i-prevprime;
                        num1 = prevprime;
                        num2 = i;
                    }
                }
                prevprime = i;
            }
        }

        return {(int) num1, (int) num2};
    }
};