// Last updated: 6/11/2026, 11:26:09 AM
class Solution {
public:
    vector<vector<int>> eve;
    int k;
    vector<vector<int>> dp;
    int rec(int ind, int taken){
        if(taken == k) return 0;
        if(taken>k) return -1e9;

        if(ind == eve.size()){
            return 0;
        }

        if(dp[ind][taken]!=-1) return dp[ind][taken];

        int radh = rec(ind+1, taken);

        int lo = ind+1;
        int hi = eve.size()-1;
        int ans = -1;

        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(eve[mid][0]>eve[ind][1]){
                ans = mid;
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }

        if(ans == -1){
            return  dp[ind][taken] = max(radh, eve[ind][2]);
        }

        return dp[ind][taken] = max(radh, eve[ind][2]+rec(ans, taken+1));
    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        eve = events;
        this->k = k;
        int n = events.size();
        dp.clear();
        dp.resize(n+1, vector<int>(k+1, -1));
        return rec(0, 0);
    }
};