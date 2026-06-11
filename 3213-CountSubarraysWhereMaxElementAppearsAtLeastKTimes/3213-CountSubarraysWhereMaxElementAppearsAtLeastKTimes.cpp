// Last updated: 6/11/2026, 11:19:25 AM
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxel = *max_element(nums.begin(), nums.end());
        int i = 0;
        int j = -1;
        int cnt = 0;
        int n = nums.size();
        long long ans = 0;
        while(i<n){
            while(j+1<n && (cnt<k)){
                j++;
                if(nums[j] == maxel){
                    cnt++;
                }
            }
            if(n-j>=0 && cnt >= k){
                ans += (n-j);
            }
            if(i>j){
                i++;
                j = i-1;
            }else{
                if(nums[i] == maxel){
                    cnt--;
                }
                i++;
            }
        }

        return ans;
    }
};