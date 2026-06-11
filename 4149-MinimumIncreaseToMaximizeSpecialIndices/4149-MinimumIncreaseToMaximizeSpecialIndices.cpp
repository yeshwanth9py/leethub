// Last updated: 6/11/2026, 11:11:53 AM
class Solution {
public:
    int n;
    vector<int> arr;
    vector<pair<long long, long long>> dp;
    pair<long long, long long> rec(long long ind){
        if(ind>=n-1) return {0, 0}; //spl no, min inc
        if(dp[ind].first != -1) return dp[ind];
        auto ans = rec(ind+1);
        if(ind-1>=0 && ind+1<n){
            long long mxn = max(arr[ind-1], arr[ind+1]);
            long long op = 0;
            if(mxn>=arr[ind]){
                op = mxn-arr[ind]+1;
            }
            auto ans2 = rec(ind+2);
            if(ans2.first+1 > ans.first){
                ans.first = ans2.first+1;
                ans.second = ans2.second+op;
            }else if(ans2.first+1 == ans.first){
                ans.first = ans2.first+1;
                ans.second = min(ans.second, ans2.second+op);
            }
        }
        return dp[ind] = ans;
    }


    long long minIncrease(vector<int>& nums) {
        n = nums.size();
        arr = nums;
        dp.resize(n+1, {-1, -1});
        auto ans = rec(1);
        return ans.second;
    }
};