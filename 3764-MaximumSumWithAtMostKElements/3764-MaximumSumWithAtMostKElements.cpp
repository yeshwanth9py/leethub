// Last updated: 6/11/2026, 11:16:11 AM

using ll = long long;
class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        ll n = grid.size();
        ll m = grid[0].size();

        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for(ll i=0; i<n; i++){
            sort(grid[i].begin(), grid[i].end());
            for(ll j=m-1; j>=max(0ll, m-limits[i]); j--){
                pq.push(grid[i][j]);
                if(pq.size()>k){
                    pq.pop();
                }
            }
        }

        ll cursum = 0;
        while(!pq.empty()){
            cursum += pq.top();
            pq.pop();
        }

        return cursum;
    }
};