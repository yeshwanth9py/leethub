// Last updated: 6/11/2026, 11:28:22 AM
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        for(int i=0; i<nums.size(); i++){
            int sz = log10(nums[i])+1;
            cnt += (sz%2==0);
        }
        return cnt;
    }
};