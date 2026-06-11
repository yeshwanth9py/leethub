// Last updated: 6/11/2026, 11:08:56 AM
class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        vector<int> ans;
        for(int el: nums){
            ump[el]++;
            if(ump[el]<=k){
                ans.push_back(el);
            }
        }

        return ans;
    }
};