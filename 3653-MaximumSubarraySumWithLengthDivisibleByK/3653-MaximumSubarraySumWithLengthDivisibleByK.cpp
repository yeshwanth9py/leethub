// Last updated: 6/11/2026, 11:16:58 AM
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        //(j-i)%k = 0;  //i+1 to j
        //j%k -i%k = 0;
        long long n = nums.size();
        unordered_map<long long, long long> ump;
        long long ps = 0;
        long long ans = -1e18;

        for(long long i=0; i<n; i++){
            ps += nums[i];
            if((i+1)%k == 0){
                ans = max(ans, ps);
            }
            long long sch = i%k;
            if(ump.find(sch) != ump.end()){
                ans = max(ans, ps-ump[sch]);
            }else{
                ump[sch] = ps;
            }

            ump[sch] = min(ump[sch], ps);
        }

        return ans;
    }
};




