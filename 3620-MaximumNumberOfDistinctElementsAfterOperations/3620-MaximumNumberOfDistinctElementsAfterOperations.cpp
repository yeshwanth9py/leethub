// Last updated: 6/11/2026, 11:17:27 AM
class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int lo = nums[0]-k;
        int cnt = 1;
        lo++;
        for(int i=1; i<nums.size(); i++){
            // cout<<lo<<" ";
            int l = nums[i]-k;
            int r = nums[i]+k;
            if(lo<l){
                lo = l;
            }
            if(lo<=r){
                cnt++;
                lo++;
            }
        }
        return cnt;
    }
};