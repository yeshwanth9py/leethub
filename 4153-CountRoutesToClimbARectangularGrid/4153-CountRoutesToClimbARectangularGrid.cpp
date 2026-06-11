// Last updated: 6/11/2026, 11:11:29 AM

#define ll long long

class Solution {
public:
    int numberOfRoutes(vector<string>& grid, int d) {
        ll n = grid.size();
        ll m = grid[0].size();
        
        ll dp[751][751][2];

        ll mod = 1e9+7;

        memset(dp, 0, sizeof(dp));

        for(ll i=n-1; i>=0; i--){
            vector<ll> sum1(m+1, 0);
            ll v = floor(sqrt(d*d - 1));

            for(ll j=0; j<m && i+1<n; j++){
                sum1[j] = (dp[i+1][j][0] + dp[i+1][j][1])%mod + (j-1>=0?sum1[j-1]:0);
                sum1[j] = (sum1[j] + mod)%mod;
            }

            for(ll j=0; j<m; j++){
                ll cr = min(m-1, v + j);
                ll cl = max(0LL, j-v);
                if(i == n-1 || grid[i][j] == '#'){
                    dp[i][j][0] = ((grid[i][j] == '#')?0:1);
                }else{
                    dp[i][j][0] = (sum1[cr] - (cl-1>=0?sum1[cl-1]:0) + mod)%mod;
                }
            }

            vector<ll> sum2(m+1, 0);
            for(ll j=0; j<m; j++){
                sum2[j] = (((j-1>=0?sum2[j-1]:0) + dp[i][j][0])%mod + mod)%mod;
            }

            for(ll j=0; j<m; j++){
                ll cr = min(j+d, m-1);
                ll cl = max(0LL, j-d);
                if(grid[i][j] == '#'){
                    dp[i][j][1] = 0;
                }else{
                    dp[i][j][1] = (sum2[cr] - (cl-1>=0?sum2[cl-1]:0) + mod)%mod;
                    dp[i][j][1] -= dp[i][j][0];
                    dp[i][j][1] = (dp[i][j][1] + mod)%mod;
                }
            }
        }

        ll ways = 0;
        for(ll j=0; j<m; j++){
            ways += (dp[0][j][0] + dp[0][j][1])%mod;
            ways = (ways%mod + mod)%mod;
        }

        return ways;
    }
};