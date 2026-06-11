// Last updated: 6/11/2026, 11:14:39 AM
class Solution {
public:
    vector<long long> allprimes;
    void sieve(){
        long long n = 1e5+11;
        allprimes.resize(1e5+11, 1);
        allprimes[0] = 0;
        allprimes[1] = 0;
        allprimes[2] = 1;
        for(long long i=2; i<n; i++){
            if(allprimes[i]){
                for(long long j=i*i; j<n; j+=i){
                    allprimes[j] = 0;
                }
            }
        }
    }
    long long splitArray(vector<int>& nums) {
        sieve();
        long long ts1 = 0;
        long long ts2 = 0;
        for(int i=0; i<nums.size(); i++){
            if(allprimes[i]){
                ts1 = ts1 + nums[i];
            }else{
                ts2 = ts2 + nums[i];
            }
        }

        return abs(ts1-ts2);
    }
};