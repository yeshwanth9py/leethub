// Last updated: 6/11/2026, 11:20:38 AM
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int j = -1;
        int i = 0;
        int n = nums.size();
        int maxlen = 0;
        while(i<n){
            while(j+1<n && nums[j+1]-nums[i]<=2*k){
                j++;
            }
            if(j-i+1>=0){
                maxlen = max(maxlen, j-i+1);
                // cout<<(j-i+1)<<endl;
            }
            // if(i>j){
            //     i++;
            //     j=i-1;
            // }else{
                i++;
            // }
        }

        return maxlen;
    }
};