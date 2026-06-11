// Last updated: 6/11/2026, 11:21:58 AM
class Solution {
public:
    long long n;
    long long m;
    vector<int> power;
    vector<int> rob;
    vector<vector<int>> fact;
    long long dp[111][111];
    long long rec(long long r1, long long f1){
        if(r1 == n){
            return 0;
        }
        if(f1>=m) return 1e18;
        if(dp[r1][f1] != -1) return dp[r1][f1];
        long long ans = rec(r1, f1+1);
        //can i take
        if(power[f1]>0){
            long long td = 0;
            for(long long i=0; i<min(1LL*(n-r1), 1LL*power[f1]); i++){
                if(r1+i>=n) break;
                td += abs(rob[r1+i]-fact[f1][0]);
                ans = min(ans, td+rec(r1+i+1, f1+1));
            }
        }
        return dp[r1][f1] = ans;
    }
    long long minimumTotalDistance(vector<int>& rob, vector<vector<int>>& fact) {
        sort(rob.begin(), rob.end());
        sort(fact.begin(), fact.end());

        n = rob.size();
        m = fact.size();
        this->fact = fact;
        this->rob = rob;

        power.resize(m, 0);
        memset(dp, -1, sizeof(dp));
        for(long long i=0; i<fact.size(); i++){
            power[i] = fact[i][1];
        }

        return rec(0, 0);
    }
};