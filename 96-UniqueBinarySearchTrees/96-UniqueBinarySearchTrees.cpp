// Last updated: 6/11/2026, 11:36:49 AM
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 1);
        if(n<2) return dp[n];
        dp[2] = 2;
        for(int i=3; i<=n; i++){
            int sum = 0;
            for(int j=1; j<=i; j++){
                int leftbst = dp[j-1];
                int rightbst = dp[i-j];
                sum += leftbst*rightbst;
            }
            cout<<sum<<" ";
            dp[i] = sum;
        }

        return dp[n];
    }
};

