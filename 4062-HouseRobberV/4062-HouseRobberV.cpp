// Last updated: 6/11/2026, 11:13:19 AM
class Solution {
public:
    vector<int> arr;
    long long dp[100100][2];
    long long rec(long long ind, long long j, long long prev){
        if(ind > j){
            return 0;
        }
        if(dp[ind][prev]!=-1) return dp[ind][prev];
        long long val = rec(ind+1, j, 0);
        if(prev == 0){
            val = max(val, arr[ind]+rec(ind+1, j, 1));
        }

        return dp[ind][prev] = val;
    }
    
    long long rob(vector<int>& arr, vector<int>& col) {
        long long i = 0;
        long long n = arr.size();
        this->arr = arr;
        long long ans = 0;
        memset(dp, -1, sizeof(dp));
        while(i<n){
            if(i+1>=n || col[i]!=col[i+1]){
                ans += arr[i];
                i++;
            }else{
                long long mxv = arr[i];
                long long j = i;
                while(j+1<n && col[j+1] == col[i]){
                    j++;
                }
                long long cura = rec(i, j, 0);
                ans += cura;
                i = j+1;
            }
        }

        return ans;
    }
};