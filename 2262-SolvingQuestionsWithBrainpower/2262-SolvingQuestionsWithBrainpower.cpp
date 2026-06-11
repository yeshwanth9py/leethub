// Last updated: 6/11/2026, 11:23:40 AM
using ll = long long;
class Solution {
public:
    vector<vector<int>> arr;
    ll dp[100001];
    ll rec(int ind){
        if(ind >= arr.size()){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        return dp[ind] = max(arr[ind][0]+rec(ind+arr[ind][1]+1), rec(ind+1));
    }
    long long mostPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        this->arr = arr;
        for(int i=0; i<=n; i++){
            dp[i] = -1;
        }
        return rec(0);
    }
};