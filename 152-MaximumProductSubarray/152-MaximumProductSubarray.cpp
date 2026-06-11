// Last updated: 6/11/2026, 11:35:35 AM
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = *(max_element(nums.begin(), nums.end()));
        int n = nums.size();

        int maxp = 1;
        int minp = 1;
        for(int i=0; i<n; i++){
            maxp = maxp*nums[i];
            minp = minp*nums[i];
            ans = max({ans, maxp, minp});
            if(minp>maxp){
                swap(maxp, minp);
            }
            if(maxp <= 0){
                maxp = 1;
            }
            if(minp>=0){
                minp = 1;
            }
        }

        return ans;

    }
};