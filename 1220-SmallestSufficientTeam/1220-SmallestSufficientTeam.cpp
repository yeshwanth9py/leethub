// Last updated: 6/11/2026, 11:29:17 AM
class Solution {
public:
    unordered_map<string, int> ump;
    vector<int> pplskills;
    int n;
    int m;
    vector<int> ansss;
    int dp[65][(1LL<<18)];
    int rec(int ind, int mask){
        if(ind == n){
            if(mask == ((1LL<<m)-1)){
                return 0;
            }
            return 1e9;
        }
        if(dp[ind][mask] != -1) return dp[ind][mask];
        int ans = rec(ind+1, mask);
        //consider this person
        int nmask = (mask | pplskills[ind]);
        
        ans = min(ans, 1+rec(ind+1, nmask));
        return dp[ind][mask] = ans;
    }

    void recg(int ind, int mask){
        if(ind == n){
            return;
        }

        int ans = rec(ind+1, mask);
        //consider this person
        int nmask = (mask | pplskills[ind]);
        
        int ans2 = 1+rec(ind+1, nmask);
        if(ans<=ans2){
            recg(ind+1, mask);
        }else{
            ansss.push_back(ind);
            recg(ind+1, nmask);
        }
    }

    vector<int> smallestSufficientTeam(vector<string>& req, vector<vector<string>>& ppl) {
        int id = 0;
        for(auto s: req){
            ump[s] = id;
            id++;
        }
        m = req.size();
        n = ppl.size();

        for(auto vec: ppl){
            int curm = 0;
            for(string s: vec){
                curm |= (1LL<<ump[s]);
            }
            pplskills.push_back(curm);
        }
        memset(dp, -1, sizeof(dp));
        rec(0, 0);
        recg(0, 0);


        return ansss;
    }
};