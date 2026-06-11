// Last updated: 6/11/2026, 11:17:10 AM
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int nop) {
        unordered_map<int, int> ump;
        vector<pair<int, int>> linesw;
        for(int el: nums){
            linesw.push_back({el-k, -1});
            linesw.push_back({el+k, 1});
            linesw.push_back({el, 0});
            ump[el]++;
        }

        sort(linesw.begin(), linesw.end());

        int noi = 0;
        int maxnoi = 0;
        for(auto el: linesw){
            if(el.second == -1){
                noi++;
            }else if(el.second == 1){
                noi--;
            }
            int curopn = min(nop, noi-ump[el.first]);
            maxnoi = max(maxnoi, curopn+ump[el.first]);
        }

        return maxnoi;
    }
};