// Last updated: 6/11/2026, 11:32:17 AM
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        for(int i=0; i<n-2; i++){
            for(int j=i+1; j<n-1; j++){
                int cs = nums[i]+nums[j];
                // int x < arr[i]+arr[j]; 
                int idx = lower_bound(nums.begin(), nums.end(), cs) - nums.begin();
                if(idx<=j) break;
                idx = idx-(j+1);
                if(idx>0){
                    ans += (idx);
                }
            }
        }

        return ans;
    }
};