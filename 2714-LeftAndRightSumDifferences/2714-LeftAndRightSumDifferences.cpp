// Last updated: 6/11/2026, 11:21:07 AM
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ls(n, 0), rs(n, 0);
        ls[0] = 0;
        for(int i=1; i<n; i++){
            ls[i] = ls[i-1]+nums[i-1];
        }
        rs[n-1] = 0;
        for(int i=n-2; i>=0; i--){
            rs[i] = rs[i+1] + nums[i+1];
            
        }
        for(int i=n-1; i>=0; i--){
            rs[i] = abs(ls[i]-rs[i]);
        }

        return rs;
    }
};