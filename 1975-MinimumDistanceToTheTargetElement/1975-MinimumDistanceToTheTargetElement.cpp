// Last updated: 6/11/2026, 11:25:41 AM
class Solution {
public:
    int getMinDistance(vector<int>& nums, int tar, int s) {
        int i = s;
        int j = s;
        int n = nums.size();
        int dis = 0;
        while(1){
            if(i>=0 && nums[i] == tar) return dis;
            if(j<n && nums[j] == tar) return dis;
            i--;
            j++;
            dis++;
        }

        return -1;
    }
};