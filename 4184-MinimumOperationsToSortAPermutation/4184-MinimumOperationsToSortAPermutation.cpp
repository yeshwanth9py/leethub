// Last updated: 6/11/2026, 11:10:56 AM
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> inctn(n, 1);
        vector<int> dectn(n, 1);
        for(int i=1; i<n; i++){
            if(nums[i]>nums[i-1]){
                inctn[i] += inctn[i-1];
            }else{
                dectn[i] += dectn[i-1];
            }
        }

        vector<int> incfn(n, 1);
        vector<int> decfn(n, 1);

        for(int i=n-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                incfn[i] += incfn[i+1];
            }else{
                decfn[i] += decfn[i+1];
            }
        }

        int minop = 1e9;
        if(incfn[0]==n) return 0;
        if(decfn[0] == n) return 1;
        
        for(int i=0; i<n; i++){
            if(i-1>=0 && nums[n-1]>=nums[i] && nums[0]>=nums[n-1]){
                int cur = incfn[i] + inctn[i-1];
                if(cur == n){
                    minop = min({minop, inctn[i-1], incfn[i]+2});
                }
            }
            if(i-1>=0 && nums[i]<=nums[i-1] && nums[i]>=nums[n-1] && nums[0]>=nums[i-1]){
                int cur = dectn[i-1] + decfn[i];
                if(cur == n){
                    minop = min({minop, dectn[i-1]+1, decfn[i]+1});
                }
            }
            if(i+1<n && nums[i]<=nums[0] && nums[i+1]>=nums[n-1] && nums[0]<=nums[n-1]){
                int cur = dectn[i] + decfn[i+1];
                if(cur == n){
                    minop = min({minop, dectn[i]+1, decfn[i+1]+1});
                }
            }
        }

        if(minop>=1e8) return -1;
        return minop;
        
    }
};