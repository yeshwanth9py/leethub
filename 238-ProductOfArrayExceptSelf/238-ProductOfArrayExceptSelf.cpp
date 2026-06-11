// Last updated: 6/11/2026, 11:34:19 AM
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefp(n, 0);
        prefp[0] = nums[0];
        for(int i=1; i<n; i++){
            prefp[i] = prefp[i-1]*nums[i];
        }

        vector<int> sufp(n, 0);
        sufp[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            sufp[i] = sufp[i+1]*nums[i];
        }

        vector<int> ans;
        for(int i=0; i<n; i++){
            int pp = (i-1>=0?prefp[i-1]:1);
            int ss = (i+1<n?sufp[i+1]:1);
            ans.push_back(pp*ss);
        }

        return ans;
    }
};