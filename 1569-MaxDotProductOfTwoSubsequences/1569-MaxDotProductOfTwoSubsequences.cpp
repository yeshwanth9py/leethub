// Last updated: 6/11/2026, 11:27:30 AM
class Solution {
public:
    vector<int> a;
    vector<int> b;
    int n1;
    int n2;
    int dp[501][501];
    int rec(int l1, int l2){
        if(l1>=n1 || l2>=n2) return -1e9;
        if(dp[l1][l2] != -1) return dp[l1][l2];
    
        int ans = max({rec(l1+1, l2), rec(l1, l2+1)});

        ans = max({ans, a[l1]*b[l2], a[l1]*b[l2]+rec(l1+1, l2+1)});
        
        
        return dp[l1][l2] = ans;
    }
    
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        // sort(nums1.begin(), nums1.end());
        // sort(nums2.begin(), nums2.end());
        a = nums1;
        b = nums2;
        n1 = nums1.size();
        n2 = nums2.size();
        memset(dp, -1, sizeof(dp));

        return rec(0, 0);

    }
};