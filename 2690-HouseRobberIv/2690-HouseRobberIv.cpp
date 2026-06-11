// Last updated: 6/11/2026, 11:21:17 AM
class Solution {
public:
    bool check(int mid, int k, vector<int> &nums){
        int taken = 0;
        int ind = 0;

        while(taken<k && ind<nums.size()){
            if(nums[ind]<=mid){
                taken++;
                ind = ind+2;
            }else{
                ind++;
            }
        }

        return taken>=k;
    }

    int minCapability(vector<int>& nums, int k) {
        int lo = *min_element(nums.begin(), nums.end());
        int hi = *max_element(nums.begin(), nums.end());
        int ans = 1e9;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(check(mid, k, nums)){
                hi = mid-1;
                ans = mid;
            }else{
                lo = mid+1;
            }
        }

        return ans;

    }
};