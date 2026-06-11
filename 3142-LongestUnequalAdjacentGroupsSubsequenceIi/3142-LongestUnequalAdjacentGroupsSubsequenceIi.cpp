// Last updated: 6/11/2026, 11:19:56 AM
class Solution {
public:
    vector<string> words;
    vector<int> groups;
    vector<string> ans;
    int dp[1002][1002];
    int dp2[1002][1002];

    bool hammingdist(int ind, int pind){
        if(ind == -1 || pind == -1){
            return 1;
        }
        if(dp2[ind][pind]!=-1) return dp2[ind][pind];
        if(words[ind].length()!=words[pind].length()){
            return 0;
        }

        int hd = 0;
        string w1 = words[ind];
        string w2 = words[pind];

        for(int i=0; i<w1.length(); i++){
            if(w1[i]!=w2[i]){
                hd++;
                if(hd>1) return dp2[ind][pind] = 0;
            }
        }

        return dp2[ind][pind] = (hd == 1);
    }

    int rec(int ind, int prevind){
        if(ind == groups.size()){
            return 0;
        }
        if(dp[ind][prevind+1]!=-1){
            return dp[ind][prevind+1];
        }
        int len = rec(ind+1, prevind);
        if((prevind==-1) || ((groups[ind] != groups[prevind]) && hammingdist(ind, prevind))){
            len = max(len, 1+rec(ind+1, ind));
        }
        return dp[ind][prevind+1] = len;
    }

    void generate(int ind, int prevind){
        if(ind == groups.size()){
            return;
        }
        int len = rec(ind+1, prevind);
        if((prevind==-1) || ((groups[ind] != groups[prevind]) && hammingdist(ind, prevind))){
            len = max(len, 1+rec(ind+1, ind));
        }

        if(len == rec(ind+1, prevind)){
            generate(ind+1, prevind);
        }else{
            ans.push_back(words[ind]);
            generate(ind+1, ind);
        }
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        this->words = words;
        this->groups = groups;
        // ans.clear();
        for(int i=0; i<=words.size()+1; i++){
            for(int j=0; j<=words.size()+1; j++){
                dp[i][j] = -1;
                dp2[i][j] = -1;
            }
        }

        rec(0, -1);
        generate(0, -1);
        return ans;
    }
};