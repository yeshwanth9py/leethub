// Last updated: 6/11/2026, 11:27:58 AM
class Solution {
public:
    int d;
    int n;
    vector<int> arr;
    int dp[1101];
    int rec(int ind){
        if(dp[ind] != -1) return dp[ind];
        int maxl = 1;
        for(int i=ind-1; i>=max(0, ind-d); i--){
            if(arr[i]<arr[ind]){
                int curl = 1 + rec(i);
                maxl = max(maxl, curl);
            }else{
                break;
            }
        }
        for(int i=ind+1; i<=min(n-1, ind+d); i++){
            if(arr[i]<arr[ind]){
                int curl = 1+rec(i);
                maxl = max(maxl, curl);
            }else{
                break;
            }
        }
        return dp[ind] = maxl;
    }
    int maxJumps(vector<int>& arrr, int d) {
        arr = arrr;
        n = arr.size();
        this->d = d;
        int ans = 0;
        memset(dp, -1, sizeof(dp));

        for(int i=0; i<n; i++){
            ans = max(ans, rec(i));
        }

        return ans;
    }
};