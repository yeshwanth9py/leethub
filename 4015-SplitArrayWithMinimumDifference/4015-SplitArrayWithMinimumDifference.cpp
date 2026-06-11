// Last updated: 6/11/2026, 11:13:51 AM
class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> decr(n, 1);
        vector<int> incr(n, 1);
        long long ts = nums[n-1];
        
        for(long long i=n-2; i>=0; i--){
            ts += nums[i];
            if(nums[i]>nums[i+1]){
                decr[i] = decr[i+1];
            }else{
                decr[i] = 0;
            }
        }

        for(long long i=1; i<n; i++){
            if(nums[i]>nums[i-1]){
                incr[i] = incr[i-1];
            }else{
                incr[i] = 0;
            }
        }

        // for(int i=0; i<n; i++){
        //     cout<<incr[i]<<" "<<decr[i]<<", ";
        // }

        long long ls = 0;
        long long ans = 1e18;
        bool valid = 0;
        for(long long i=0; i<n-1; i++){
            ls += nums[i];
            long long rs = ts - ls;
            if(incr[i] && decr[i+1]){
                ans = min(ans, abs(ls-rs));
                valid = 1;
            }
        }

        if(!valid) return -1;
        return ans;
    }
};