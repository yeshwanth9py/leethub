// Last updated: 6/11/2026, 11:30:49 AM
class Solution {
public:
    int n;
    int k;
    int mp;
    double dp[20010];
    double rec(){
        // if(sc>=k){
        //     return sc<=n;
        // }

        // if(seen[sc]==1) return dp[sc];
        // double prob = 0;
        // for(int i=1; i<=mp; i++){
        //     prob += rec(i+sc)*(1.0/mp);
        // }
        // seen[sc] = 1;
        // return dp[sc] = prob;
        if(k == 0) return 1;

        int limit = k-1+mp;
        vector<double> suff(20010, 0.0);
        for(int sc = limit; sc>=0; sc--){
            if(sc>=k){
                dp[sc] = (sc<=n);
                suff[sc] = suff[sc+1]+dp[sc];
                continue;
            }
            double prob = suff[sc+1] - suff[sc+mp+1];
            // for(int i=1; i<=mp; i++){
            //     prob += dp[sc+i] * (1.0/mp);
            // }
            dp[sc] = prob*(1.0/mp);
            suff[sc] = suff[sc+1] + dp[sc];
        }
        return dp[0];

    }


    double new21Game(int nn, int kk, int maxPts) {
        n = nn;
        k = kk;
        mp = maxPts;
        memset(dp, 0, sizeof(dp));
        return rec();
    }
};