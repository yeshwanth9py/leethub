// Last updated: 6/11/2026, 11:21:59 AM
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int l = 0;
        int n = nums.size();
        long long res = 0;

        long long cursum = 0;
        unordered_set<int> us;
        for(int r=0; r<n; r++){
            while(us.contains(nums[r])>0 || r-l+1>k){
                us.erase(nums[l]);
                cursum -= nums[l];
                l++;
            }

            us.insert(nums[r]);
            cursum += nums[r];
            if(r-l+1 == k){
                res = max(res, cursum);
            }
            
        }

        return res;
    }
};