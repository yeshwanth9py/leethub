// Last updated: 6/11/2026, 11:12:35 AM
class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        int maxv = nums[0]+nums[1]-nums[2];
        int n = nums.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k<n; k++){
                    if(i == j || j == k || i == k) continue;
                    int a = nums[i];
                    int b = nums[j];
                    int c = nums[k];
                    maxv = max(maxv, a+b-c);
                }
            }
        }

        return maxv;
    }
};