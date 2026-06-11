// Last updated: 6/11/2026, 11:27:36 AM
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        vector<int> onep;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] == 1) onep.push_back(i);
        }
        if(onep.size() <= 1) return 1;
        for(int i=0; i<onep.size()-1; i++){
            if((onep[i+1]-onep[i]-1) < k) return 0;
        }
        return 1;
    }
};