// Last updated: 6/11/2026, 11:32:21 AM
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> ump;
        for(int el: nums) ump[el]++;
        int mx = 0;
        for(auto el: ump){
            if(ump.count(el.first+1)){
                mx = max(mx, ump[el.first]+ump[el.first+1]);
            }
        }

        if(ump.size()<=1) return 0;
        return mx;
    }
};