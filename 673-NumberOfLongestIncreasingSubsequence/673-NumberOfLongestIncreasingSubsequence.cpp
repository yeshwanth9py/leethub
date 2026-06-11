// Last updated: 6/11/2026, 11:32:01 AM
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n, 1);
        vector<int> cnt(n, 1);

        int maxi = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i]>nums[j] && lis[i]<lis[j]+1){
                    lis[i] = lis[j]+1;
                    cnt[i] = cnt[j];
                }else if(nums[i]>nums[j] && lis[i]==lis[j]+1){
                    cnt[i]+=cnt[j];
                }
            }

            maxi = max(maxi, lis[i]);
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            if(lis[i] == maxi){
                ans += cnt[i];
            }
        }  

        return ans;
    }
};