// Last updated: 6/11/2026, 11:37:16 AM
class Solution {
public:
    int n, m;
    string s;
    string t;
    int dp[501][501];
    int rec(int id1, int id2){
        if(id2 == m || id1 == n){
            return (m-id2) + (n-id1);
        }
        if(dp[id1][id2]!=-1) return dp[id1][id2];

        int minop = 1e9;
        if(s[id1] == t[id2]){
            minop = min(minop, rec(id1+1, id2+1));
        }

        //delete
        minop = min(minop, 1+rec(id1+1, id2));

        //replace
        minop = min(minop, 1+rec(id1+1, id2+1));

        //insert
        minop = min(minop, 1+rec(id1, id2+1));

        return dp[id1][id2] = minop;
    }

    int minDistance(string word1, string word2) {
        n = word1.size();
        m = word2.size();
        s = word1;
        t = word2;
        memset(dp, -1, sizeof(dp));
        return rec(0, 0);
    }
};