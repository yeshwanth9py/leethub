// Last updated: 6/11/2026, 11:20:24 AM
class Solution {
public:
    const long long mod = 12345;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& arr) {
        long long n = arr.size();
        long long m = arr[0].size();

        vector<vector<long long>> sufp(n, vector<long long>(m, 1));
        vector<vector<long long>> pref(n, vector<long long>(m, 1));

        long long pp = 1;

        for(long long i=n-1; i>=0; i--){
            for(long long j=m-1; j>=0; j--){
                pp = (pp*arr[i][j])%mod;
                sufp[i][j] = pp;
            }
        }

        pp = 1;
        for(long long i=0; i<n; i++){
            for(long long j=0; j<m; j++){
                pp = (pp*arr[i][j])%mod;
                pref[i][j] = pp;
            }
        }

        vector<vector<int>> ans(n, vector<int>(m, 0));

        for(long long i=0; i<n; i++){
            for(long long j=0; j<m; j++){
                long long cp;
                if(j-1>=0){
                    cp = pref[i][j-1];
                }else{
                    cp = (i-1>=0?pref[i-1][m-1]:1);
                }

                if(j+1<m){
                    cp = ((cp*sufp[i][j+1])%mod + mod)%mod;
                }else{
                    cp = ((cp*(i+1<n?sufp[i+1][0]:1))%mod + mod)%mod;
                }

                ans[i][j] = cp;
            }
        }

        return ans;

    }
};