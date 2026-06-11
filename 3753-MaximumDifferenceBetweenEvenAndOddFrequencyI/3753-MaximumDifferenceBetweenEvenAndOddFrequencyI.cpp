// Last updated: 6/11/2026, 11:16:20 AM
class Solution {
public:
    int maxDifference(string s) {
        int max_o = 0;
        int min_e = 1e9;

        unordered_map<char, int> ump;
        
        for(int i=0; i<s.size(); i++){
            ump[s[i]]++;
        }

        for(auto el: ump){
            if((el.second)&1){
                max_o = max(max_o, (el.second));
            }else{
                min_e = min(min_e, (el.second));
            }
        }
        
        return max_o-min_e;

        
    }
};