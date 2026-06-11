// Last updated: 6/11/2026, 11:19:58 AM
class Solution {
public:
    vector<string> word;
    vector<int> group;
    int dp[101][3];
    vector<string> ans;

    int rec(int ind, int prev) {
        if (ind == group.size()) 
            return 0;
        if(dp[ind][prev+1]!=-1){
            return dp[ind][prev+1];
        }
        int len = rec(ind+1, prev);

        if (prev == -1 || group[ind] != prev) {
            len = max(len, 1 + rec(ind+1, group[ind]));
        }
        
        return dp[ind][prev+1] = len;
    }

    void generate(int ind, int prev){
        if (ind == group.size()) 
            return;

        int len = rec(ind+1, prev);

        if (prev == -1 || group[ind] != prev) {
            len = max(len, 1 + rec(ind+1, group[ind]));
        }

        if(len == 1 + rec(ind+1, group[ind])){
            ans.push_back(word[ind]);
            generate(ind+1, group[ind]);
        }else{
            generate(ind+1, prev);
        }
    }

    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        this->word  = words;
        this->group = groups;
        memset(dp, -1, sizeof(dp));
        // rec(0, -1);
        generate(0, -1); 

        return ans;
    }
};
