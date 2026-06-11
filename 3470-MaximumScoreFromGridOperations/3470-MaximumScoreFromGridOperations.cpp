// Last updated: 6/11/2026, 11:18:06 AM
class Solution {
public:
    long long n;
    vector<vector<long long>> pref;
    long long dp[111][4][111];

    long long rec(long long c, long long pc, long long pr){
        if(c == n){
            return 0;
        }

        if(dp[c][pc][pr] != -1) return dp[c][pc][pr];

        long long ans = 0;
        if(pc == 1 || pc == 3){
            ans = max(ans, rec(c+1, 2, pr));
        }

        if(pc == 2){
            ans = max(ans, rec(c+1, 0, pr));
        }

        if(pc == 0){
            ans = max(ans, rec(c+1, 0, pr));
        }

        for(long long r=0; r<n; r++){
            long long lefts = (c-1>=0?pref[r][c-1]:0);

            if(pc == 3){
                if(pr>=r){
                    lefts = -pref[r][c];
                    long long rights = (c+1<n?pref[r][c+1]:0);
                    long long cur = lefts + rights + rec(c+1, 3, r);
                    ans = max(ans, cur);
                }
            }

            if(pc == 1){
                if(pr>=r){
                    lefts = -pref[r][c];
                    long long rights = (c+1<n?pref[r][c+1]:0);
                    long long cur = lefts + rights + rec(c+1, 3, r);
                    ans = max(ans, cur);
                }else{
                    lefts = -pref[pr][c] + (c-1>=0?pref[r][c-1]:0) - ((c-1>=0)?pref[pr][c-1]:0);
                    long long rights = (c+1<n?pref[r][c+1]:0);
                    long long cur = lefts + rights + rec(c+1, 1, r);
                    ans = max(ans, cur);
                }
            }

            if(pc == 2){
                if(pr>=r){
                    lefts = 0;
                    long long rights = (c+1<n?pref[r][c+1]:0);
                    long long cur = lefts + rights + rec(c+1, 1, r);
                    ans = max(ans, cur);
                }else{
                    lefts = pref[r][c-1] - (pref[pr][c-1]);
                    long long rights = (c+1<n?pref[r][c+1]:0);
                    long long cur = lefts + rights + rec(c+1, 1, r);
                    ans = max(ans, cur);
                }
            }

            if(pc == 0){
                long long rights = (c+1<n?pref[r][c+1]:0);
                long long cur = lefts + rights + rec(c+1, 1, r);
                ans = max(ans, cur);
            }
        }

        return dp[c][pc][pr] = ans;
    }


    long long maximumScore(vector<vector<int>>& arr) {
        n = arr.size();
        pref.resize(n, vector<long long>(n, 0));
        memset(dp, -1, sizeof(dp));
        for(int j=0; j<n; j++){
            for(int i=0; i<n; i++){
                pref[i][j] = arr[i][j] + (i-1>=0?pref[i-1][j]:0);
            }
        }

        return rec(0, 0, 0);

    }
};