// Last updated: 6/11/2026, 11:38:39 AM
class Solution {
public:
    string s;
    string p;
    int dp[21][21];
    int rec(int i, int j){
        if(i>=s.size() && j>=p.size()) return 1;
        if(j>=p.size()){
            return 0;
        }
        if(i>=s.size()){
            if(p[j] != '*'  &&  p[j+1] == '*'){ 
                return dp[i][j] = rec(i, j+2);
            }else if(p[j] == '*'){
                return dp[i][j] = rec(i, j+1);
            }
            return dp[i][j] = 0;
        }

        if(dp[i][j] != -1) return dp[i][j];

        bool pos = 0;
        if(s[i] == p[j] || p[j] == '.'){
            pos |= rec(i+1, j+1);
        }

        if(p[j] == '*'){
            pos |= rec(i, j+1);
            int pc = p[j-1]-'a';
            if(p[j-1] == '.'){
                pc = 26;
            }
            
            for(int nc=i; nc<s.size(); nc++){
                if(s[nc]-'a' == pc || pc == 26){
                    pos |= rec(nc+1, j+1);
                }else{
                    break;
                }
            }
        }

        if(j+1<p.size() && p[j+1] == '*'){
            pos |= rec(i, j+2);
        }
        
        return dp[i][j] = pos;
    }

    bool isMatch(string s, string p) {
        this->s = s;
        this->p = p;
        memset(dp, -1, sizeof(dp));
        return rec(0, 0);
    }
};