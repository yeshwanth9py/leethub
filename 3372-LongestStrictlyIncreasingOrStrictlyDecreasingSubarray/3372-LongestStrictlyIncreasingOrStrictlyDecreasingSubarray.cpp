// Last updated: 6/11/2026, 11:18:38 AM
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int i = 0;
        int j=0;
        int n = nums.size();
        int maxinc = 1;
        while(i<n){
            while(j+1<n && nums[j+1]>nums[j]){
                j++;
                maxinc = max(maxinc, j-i+1);
            }
            i = j+1;
            j = i;
        }

        int maxdec = 1;
        i=0;
        j=0;
        while(i<n){
            while(j+1<n && nums[j+1]<nums[j]){
                j++;
                maxdec = max(maxdec, j-i+1);
            }
            i=j+1;
            j=i;
        }

        return max(maxinc, maxdec);

    }
};