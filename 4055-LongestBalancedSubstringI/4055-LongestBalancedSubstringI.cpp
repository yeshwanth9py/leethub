// Last updated: 6/11/2026, 11:13:27 AM
class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            unordered_map<char, int> ump;
            for(int j=i; j<n; j++){
                ump[s[j]]++;
                int maxfc = ump[s[j]];
                
                bool flag = 1;
                for(auto el: ump){
                    if(el.second == 0 || el.second == maxfc){
                        continue;
                    }else{
                        flag = 0;
                        break;
                    }
                }

                if(flag){
                    ans = max(ans, j-i+1);
                }
            }
        }

        return ans;
    }
};