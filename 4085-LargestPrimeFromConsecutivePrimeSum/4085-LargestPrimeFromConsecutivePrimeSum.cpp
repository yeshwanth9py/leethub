// Last updated: 6/11/2026, 11:12:56 AM
class Solution {
public:
    vector<long long> primes;
    vector<long long> isprime;
    vector<long long> prefprimes;
    vector<long long> goods;
    void pre(long long n){
        isprime.resize(n+1, 1);
        isprime[1] = 0;
        isprime[0] = 0;
        for(long long i=2; i<=n; i++){
            if(isprime[i]){
                for(long long j=i*i; j<=n; j=j+i){
                    isprime[j] = 0;
                }   
            }
        }

        for(long long i=2; i<=n; i++){
            if(isprime[i]){
                primes.push_back(i);
            }
        }
        long long m = primes.size();
        prefprimes.resize(m, 0);
        prefprimes[0] = primes[0];
        goods.push_back(2);
        // cout<<2<<" ";
        for(long long i=1; i<m; i++){
            prefprimes[i] = prefprimes[i-1] + primes[i];
            if(prefprimes[i]>n) continue;
            if(isprime[prefprimes[i]]){
                goods.push_back(prefprimes[i]);
                // cout<<prefprimes[i]<<" ";
            }
        }
    }
    int largestPrime(int n) {
        if(n == 1){
            return 0;
        }
        pre(n);
        // if(n == 2){
        //     return 2;
        // }
        // cout<<<<endl;
        return goods.back();
    }
};