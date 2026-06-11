// Last updated: 6/11/2026, 11:20:36 AM
class Solution {
public:
    bool isGood(vector<int>& nums) {
        int sz = nums.size();
        int n = sz-1;
        unordered_map<int, int> ump;

        for(int el: nums){
            ump[el]++;
        }

        for(int i=1; i<n; i++){
            if(ump[i] != 1) return 0;
        }
        return (ump[n] == 2);
    }
};