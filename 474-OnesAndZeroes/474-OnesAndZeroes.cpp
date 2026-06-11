// Last updated: 6/11/2026, 11:33:00 AM
class Solution {
public:
    vector<pair<int, int>> arr;
    int sz;
    int dp[601][101][101];
    int rec(int ind, int remz, int remo){
        if(remz<0 || remo<0) return -1e9;
        if(ind == sz){
            return 0;
        }

        if(dp[ind][remz][remo]!=-1) return dp[ind][remz][remo];
        //take
        int ans = 1+rec(ind+1, remz-arr[ind].first, remo-arr[ind].second);

        //dont take
        ans = max(ans, rec(ind+1, remz, remo));

        return dp[ind][remz][remo] = ans;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        for(auto s: strs){
            int z = 0;
            int o = 0;
            for(char ch: s){
                if(ch == '0'){
                    z++;
                }else{
                    o++;
                }
            }
            arr.push_back({z, o});
        }
        sz = arr.size();
        memset(dp, -1, sizeof(dp));
        return rec(0, m, n);
    }
};