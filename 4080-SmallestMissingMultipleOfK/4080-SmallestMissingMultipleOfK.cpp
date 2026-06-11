// Last updated: 6/11/2026, 11:12:59 AM
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        for(int el: nums){
            ump[el] = 1;
        }
        for(int i=k; i<=100*1LL*k; i=i+k){
            if(ump.find(i) == ump.end()) return i;
        }
        return 101*k;
    }
};