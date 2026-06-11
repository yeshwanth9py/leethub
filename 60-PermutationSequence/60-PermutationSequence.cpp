// Last updated: 6/11/2026, 11:37:29 AM
class Solution {
public:
    int dp[12];
    int fact(int n){
        if(n <= 1){
            return 1;
        }
        if(dp[n]!=-1) return dp[n];
        return dp[n] = n*fact(n-1);
    }
    string getPermutation(int n, int k) {
        vector<int> elems;
        // dp[0] = -1;
        for(int i=1; i<=n; i++){
            elems.push_back(i);
            // dp[i] = -1;
        }
        memset(dp, -1, sizeof(dp));

        int sz = n;
        string ans = "";
        k--;
        while(sz>0){
            int ind = k/fact(sz-1);
            ans += to_string(elems[ind]);
            elems.erase(elems.begin()+ind);
            k = k-ind*fact(sz-1);
            sz = sz-1;
        }

        return ans;
    }
};