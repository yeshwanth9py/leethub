// Last updated: 6/11/2026, 11:18:15 AM
class Solution {
public:
    vector<long long> arr;
    long long n;
    map<long long, long long> ump;
    long long dp[100100];
    long long rec(long long ind){
        if(ind>=n) return 0;
        if(dp[ind]!=-1) return dp[ind];
        long long val = rec(ind+1);
        auto nxt = lower_bound(arr.begin()+ind+1, arr.end(), arr[ind]+3);
        if(nxt == arr.end()){
            return dp[ind] = max(val, (1LL*arr[ind]*ump[arr[ind]]));
        }
        long long nexti = nxt-arr.begin();
        val = max(val, (1LL*arr[ind]*ump[arr[ind]]) + rec(nexti));
        return dp[ind] = val;
    }

    long long maximumTotalDamage(vector<int>& power) {
        for(long long el: power){
            ump[el]++;
        }
        for(auto el: ump){
            arr.push_back(el.first);
        }
        sort(arr.begin(), arr.end());
        n = arr.size();
        // for(int i=0; i<n; i++){
        //     cout<<arr[i]<<" ";
        // }
        memset(dp, -1, sizeof(dp));

        return rec(0);
    }
};