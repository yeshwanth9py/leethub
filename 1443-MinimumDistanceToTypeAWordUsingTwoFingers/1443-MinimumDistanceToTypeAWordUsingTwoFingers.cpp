// Last updated: 6/11/2026, 11:28:11 AM
class Solution {
public:
    vector<pair<int,int>> ump;
    int n;
    string s;
    int dp[301][26][26];
    int rec(){
        // if(ind == n){
        //     return 0;
        // }
        // if(dp[ind][f1][f2] != -1) return dp[ind][f1][f2];

        // int ans = 1e9;
        // auto [cx, cy] = ump[s[ind]-'A'];

        // //w1
        // auto [px1, py1] = ump[f1];
        // ans = min(ans, abs(px1-cx)+abs(py1-cy) + rec(ind+1, s[ind]-'A', f2));

        // //w2
        // auto [px2, py2] = ump[f2];
        // ans = min(ans, abs(px2-cx)+abs(py2-cy) + rec(ind+1, f1, s[ind]-'A'));
        // return ans;
        int actans = 1e9;
        for(int ind=n; ind>=0; ind--){
            for(int f1=0; f1<26; f1++){
                for(int f2=0; f2<26; f2++){
                    if(ind == n){
                        dp[ind][f1][f2] = 0;
                        continue;
                    }
                    int ans = 1e9;
                    auto [cx, cy] = ump[s[ind]-'A'];
                    //w1
                    auto [px1, py1] = ump[f1];
                    ans = min(ans, abs(px1-cx)+abs(py1-cy) + dp[ind+1][s[ind]-'A'][f2]);

                    //w2
                    auto [px2, py2] = ump[f2];
                    ans = min(ans, abs(px2-cx)+abs(py2-cy) + dp[ind+1][f1][s[ind]-'A']);
                    dp[ind][f1][f2] = ans;

                    if(ind == 0){
                        actans = min(actans, ans);
                    }
                }
            }
        }

        return actans;

    }

    int minimumDistance(string s) {
        this->s = s;
        n = s.size();
        int r = 0;
        int c = 0;
        // memset(dp, -1, sizeof(dp));
        ump.resize(26, {-1, -1});
        for(int i=0; i<26; i++){
            ump[i] = {r, c};
            c++;
            if(c>=6){
                c = 0;
                r++;
            }
        }

        // cout<<ump[25].first<<" "<<ump[25].second<<" ";

       return rec();

        // return ans;
    }
};