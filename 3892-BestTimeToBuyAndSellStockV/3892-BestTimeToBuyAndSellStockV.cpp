// Last updated: 6/11/2026, 11:14:49 AM
class Solution {
public:
    long long n;
    vector<int> pr;
    long long dp[1011][2][3][1011];
    long long rec(int k){  //0 buy, 1 sell
        // if(rem<0) return -1e18;
        // if(ind == n){
        //     if(tra == 2) return -1e18;
        //     return 0;
        // }
        // if(dp[ind][ty][tra][rem] != -1) return dp[ind][ty][tra][rem];

        // long long op1 = rec(ind+1, ty, tra, rem);

        // if(ty == 0){
        //     op1 = max(op1, -pr[ind] + rec(ind+1, 1, 1, rem-1));
        //     op1 = max(op1, pr[ind]+rec(ind+1, 1, 2, rem-1));
        // }else{
        //     if(tra == 2){
        //         op1 = max(op1, -pr[ind]+rec(ind+1, 0, 0, rem));
        //     }else{
        //         op1 = max(op1, pr[ind]+rec(ind+1, 0, 0, rem));
        //     }
        // }

        // return dp[ind][ty][tra][rem] = op1;
        vector<vector<vector<vector<long long>>>> dp;
        dp.resize(n+1, vector<vector<vector<long long>>>(2, vector<vector<long long>>(3, vector<long long>(k+1, 0))));

        for(int ind=n; ind>=0; ind--){
            for(int ty=0; ty<2; ty++){
                for(int tra = 0; tra<3; tra++){
                    for(int rem=0; rem<=k; rem++){
                        if(ind == n){
                            if(tra == 2){
                                dp[ind][ty][tra][rem] = -1e14;
                            }else{
                                dp[ind][ty][tra][rem] = 0;
                            }
                            continue;
                        }

                        long long op1 = dp[ind+1][ty][tra][rem];

                        if(ty == 0){
                            if(rem-1<0) continue;
                            op1 = max(op1, -pr[ind] + dp[ind+1][1][1][rem-1]);
                            op1 = max(op1, pr[ind]+ dp[ind+1][1][2][rem-1]);
                        }else{
                            if(tra == 2){
                                op1 = max(op1, -pr[ind]+dp[ind+1][0][0][rem]);
                            }else{
                                op1 = max(op1, pr[ind]+dp[ind+1][0][0][rem]);
                            }
                        }

                        dp[ind][ty][tra][rem] = op1;
                    }
                }
            }
        }

        return dp[0][0][0][k];


    }
    long long maximumProfit(vector<int>& prices, int k) {
        pr = prices;
        n = pr.size();
        return rec(k);
    }
};