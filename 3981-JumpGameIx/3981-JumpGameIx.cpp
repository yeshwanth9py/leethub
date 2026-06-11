// Last updated: 6/11/2026, 11:14:14 AM
class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftmax(n, 0);
        for(int i=0; i<n; i++){
            leftmax[i] = max((i-1>=0?leftmax[i-1]:0), nums[i]);
        }

        int rimin = 1e9;
        vector<int> ans(n, 0);
        for(int i=n-1; i>=0; i--){
            if(leftmax[i]<=rimin){
                ans[i] = leftmax[i];
            }else{
                ans[i] = ans[i+1];
            }
            rimin = min(rimin, nums[i]);
        }

        return ans;
    }
};


