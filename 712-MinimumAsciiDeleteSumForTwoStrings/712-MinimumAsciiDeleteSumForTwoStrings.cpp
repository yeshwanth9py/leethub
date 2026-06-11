// Last updated: 6/11/2026, 11:31:50 AM
class Solution {
public:
    string s1;
    string s2;
    int dp[1001][1001];
    int rec(int i, int j){
        if(i == s1.size() || j == s2.size()){
            if(i<s1.size()){
                int cs = 0;
                while(i<s1.size()){
                    cs += (s1[i]-'a')+'a';
                    i++;
                }
                return cs;
            }
            
            if(j<s2.size()){
                int cs = 0;
                while(j<s2.size()){
                    cs += (s2[j]-'a')+'a';
                    j++;
                }
                return cs;
            }

            return 0;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i] == s2[j]){
            return rec(i+1, j+1);
        }

        return dp[i][j] = min((s1[i]-'a')+'a' + rec(i+1, j), (s2[j]-'a') + 'a' + rec(i, j+1));
    }


    int minimumDeleteSum(string s1, string s2) {
        this->s1 = s1;
        this->s2 = s2;
        memset(dp, -1, sizeof(dp));
        return rec(0, 0);
    }
};