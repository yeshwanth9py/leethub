// Last updated: 6/11/2026, 11:29:26 AM
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Step 1: Compute LCS DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= m; j++) {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        // Step 2: Construct SCS starting from i=0, j=0
        int i = n, j = m;
        string lss = "";

        while (i >0 && j >0) {
            if (str1[i-1] == str2[j-1]) {
                lss += str1[i-1];
                i--;
                j--;
            } else if (dp[i - 1][j] >= dp[i][j - 1]) {  // Navigate based on the DP table
                lss += str1[i-1];
                i--;
            } else {
                lss += str2[j-1];
                j--;
            }
        }

        // Step 3: Append remaining characters from str1 and str2
        while (i > 0) {
            lss += str1[i-1];
            i--;
        }

        while (j > 0) {
            lss += str2[j-1];
            j--;
        }

        reverse(lss.begin(), lss.end());

        return lss;
    }
};
