// Last updated: 6/11/2026, 11:25:32 AM

class Solution {
public:
    long long n;
    long long vis[19][(1LL<<17)];
    long long dp[19][(1LL<<17)];
    long long rec(long long ind, long long mask, vector<int> &arr, vector<int> &brr){
        if(ind == n){
            return 0;
        }
        if(vis[ind][mask] != -1) return dp[ind][mask];
        long long mins = 1e9;
        for(long long i=0; i<n; i++){
            if((mask & (1LL<<i)) == 0){
                long long nmask = (mask | (1LL<<i));
                long long curs = (arr[ind]^brr[i]) + rec(ind+1, nmask, arr, brr);
                mins = min(mins, curs);
            }
        }
        vis[ind][mask] = 1;
        return dp[ind][mask] = mins;
    }

    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        n = nums2.size();
        memset(dp, -1, sizeof(dp));
        memset(vis, -1, sizeof(vis));
        return rec(0, 0, nums1, nums2);
    }
};