// Last updated: 6/11/2026, 11:38:11 AM
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int st = -1;
        int lo = 0;
        int hi = nums.size()-1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(nums[mid] == target){
                st = mid;
                hi = mid-1;
            }else if(nums[mid]>target){
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }
        if(st == -1){
            return {-1, -1};
        }
        int en = st;
        lo = en+1;
        hi = nums.size()-1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(nums[mid] == target){
                en = mid;
                lo = mid+1;
            }else if(nums[mid]>target){
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }
        return {st, en};
    }
};