// Last updated: 6/11/2026, 11:13:54 AM
class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int avg = sum/n;
        int sm = 1e9;
        sort(nums.begin(), nums.end());
        int sch = max(1, avg+1);
        for(int el: nums){
            if(el==sch){
                sch++;
            }
        }

        return sch;
    }
};