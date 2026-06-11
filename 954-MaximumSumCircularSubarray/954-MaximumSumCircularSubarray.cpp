// Last updated: 6/11/2026, 11:30:19 AM
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftmax(n, 0);
        vector<int> rightmax(n, 0);
        int cs = 0;
        int ms = nums[0];
        for(int i=0; i<n; i++){
            cs += nums[i];
            ms = max(ms, cs);
            leftmax[i] = max(((i-1>=0)?leftmax[i-1]:-100000), cs);
        }

        cs = 0;
        for(int i=n-1; i>=0; i--){
            cs += nums[i];
            ms = max(ms, cs);
            rightmax[i] = max(((i+1<n)?rightmax[i+1]:-100000), cs);
        }
        // for(int i=0; i<n; i++){
        //     cout<<leftmax[i]<<" ";
        // }
        // cout<<endl;

        // for(int i=n-1; i>=0; i--){
        //     cout<<rightmax[i]<<" ";
        // }
        // cout<<endl;

        ms = -1e9;
        for(int i=0; i<n-1; i++){
            ms = max(leftmax[i]+rightmax[i+1], ms);
        }
        cs = 0;
        for(int i=0; i<n; i++){
            cs += nums[i];
            ms = max(ms, cs);
            if(cs<0) cs = 0;
        }
        return ms;
    }
};