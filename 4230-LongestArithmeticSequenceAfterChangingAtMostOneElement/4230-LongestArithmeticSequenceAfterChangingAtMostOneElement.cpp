// Last updated: 6/11/2026, 11:10:17 AM
class Solution {
public:
    int dp1[100100];
    int dp2[100100];
    int n;
    int longestArithmetic(vector<int>& nums) {
        n = nums.size();
        int maxl = 1;

        dp2[n-1] = 1;
        int d = nums[n-2]-nums[n-1];
        for(int i=n-2; i>=0; i--){
            if(nums[i] - nums[i+1] == d){
                dp2[i] = dp2[i+1]+1;
            }else{
                dp2[i] = 2;
                d = nums[i] - nums[i+1];
            }
            maxl = max(maxl, dp2[i]);
        }

        dp1[0] = 1;
        d = nums[1] - nums[0];
        for(int i=1; i<n; i++){
            if(nums[i]-nums[i-1] == d){
                dp1[i] = dp1[i-1]+1;
            }else{
                dp1[i] = 2;
                d = nums[i]-nums[i-1];
            }
            maxl = max(maxl, dp1[i]);
        }

        // for(int i=0; i<n; i++){
        //     cout<<dp1[i]<<" ";
        // }
        // cout<<endl;

        // for(int i=0; i<n; i++){
        //     cout<<dp2[i]<<" ";
        // }
        // cout<<endl;

        
        for(int i=0; i<n; i++){
            if(i-2>=0 && i+2<n){
                int d = nums[i-2]-nums[i-1];
                if(d == nums[i+1]-nums[i+2] && nums[i-1]-2*d == nums[i+1]){
                    maxl = max(maxl, dp1[i-1]+dp2[i+1]+1);
                }
            }
            if(i-2>=0 && i+1<n){
                int d = nums[i-2]-nums[i-1];
                if(nums[i-1]-2*d == nums[i+1]){
                    maxl = max(maxl, dp1[i-1]+2);
                }
            }
            if(i+2<n && i-1>=0){
                int d = nums[i+1]-nums[i+2];
                if(nums[i-1]-2*d == nums[i+1]){
                    maxl = max(maxl, dp2[i+1]+2);
                }
            }
            if(i-1>=0){
                maxl = max(maxl, dp1[i-1]+1);
            }
            if(i+1<n){
                maxl = max(maxl, dp2[i+1]+1);
            }
        }

        return maxl;

    }
};