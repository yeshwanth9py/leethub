// Last updated: 6/11/2026, 11:12:46 AM
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> incfwd(n, 1);
        vector<int> incbwd(n, 1);

        for(int i=1; i<n; i++){
            if(nums[i]>=nums[i-1]){
                incbwd[i] = incbwd[i-1]+1;
            }
        }

        for(int i=n-2; i>=0; i--){
            if(nums[i]<=nums[i+1]){
                incfwd[i] = incfwd[i+1]+1;
            }
        }

        // for(int i=0; i<n; i++){
        //     cout<<incbwd[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0; i<n; i++){
        //     cout<<incfwd[i]<<" ";
        // }
        // cout<<endl;

        int ans = 1;
        for(int i=0; i<n; i++){
            if(i+1<n && i-1>=0 && nums[i+1]>=nums[i-1]){
                int cur = incfwd[i+1]+incbwd[i-1]+1;
                ans = max(ans, cur);
            }
            if(i-1>=0){
                int cur = incbwd[i-1]+1;
                ans = max(cur, ans);
            }
            if(i+1<n){
                int cur = incfwd[i+1]+1;
                ans = max(ans, cur);
            }
        }

        return ans;
        
    }
};