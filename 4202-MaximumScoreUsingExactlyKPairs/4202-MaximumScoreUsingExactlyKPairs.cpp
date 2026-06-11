// Last updated: 6/11/2026, 11:10:42 AM
class Solution {
public:
    long long n;
    long long m;
    vector<int> nums1;
    vector<int> nums2;
    long long k;
    long long dp[101][101][101];
    long long vis[101][101][101];
    
    long long rec(long long i1, long long i2, long long el){
        if(el == k){
            return 0;
        }
        if(i1>=n || i2>=m){
            return -1e18;
        }
        if(vis[i1][i2][el] != -1) return dp[i1][i2][el];
        
        long long tb = 1LL*nums1[i1]*nums2[i2] + rec(i1+1, i2+1, el+1);
        long long sk1 = rec(i1+1, i2, el);
        long long sk2 = rec(i1, i2+1, el);
        
        vis[i1][i2][el] = 1;
        return dp[i1][i2][el] = max({sk1, sk2, tb});
    }
    
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        this->k = k;
        memset(dp, -1, sizeof(dp));
        memset(vis, -1, sizeof(vis));
        n = nums1.size();
        m = nums2.size();
        return rec(0, 0, 0);
    }
};