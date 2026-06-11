// Last updated: 6/11/2026, 11:36:12 AM
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> ump;
        for(int el: nums) ump[el] = 1;
        int ans = 0;
        for(auto elem: ump){
            int el = elem.first;
            if(ump.find(el-1) != ump.end()) continue;
            int cur = el;
            int cnt = 0;
            while(1){
                if(ump.find(cur) != ump.end()){
                    cur++;
                    cnt++;
                }else{
                    break;
                }
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};