// Last updated: 6/11/2026, 11:22:10 AM
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        int cnt = 0;
        int mxx = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == mx){
                cnt++;
                mxx = max(mxx, cnt);
            }else{
                cnt = 0;
            }
        }
        return mxx;
    }
};