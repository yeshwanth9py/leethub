// Last updated: 6/11/2026, 11:20:44 AM
class Solution {
public:
    int n;
    vector<int> arr;
    int tgt;
    int dp[1010];
    int rec(int idx){
        cout<<idx<<" ";
        if(idx == n-1){
            return 0;
        }
        if(dp[idx] != -1) return dp[idx];
        int ans = -1e9;
        for(int nidx=idx+1; nidx<n; nidx++){
            if(abs(arr[nidx] - arr[idx]) <= tgt){
                int cur = 1 + rec(nidx);
                ans = max(ans, cur);
            }
        }

        return dp[idx] = ans;
    }

    int maximumJumps(vector<int>& nums, int t) {
        n = nums.size();
        tgt = t;
        arr = nums;
        memset(dp, -1, sizeof(dp));

       int ans = rec(0);
       if(ans<0) return -1;
       return ans;
    }
};