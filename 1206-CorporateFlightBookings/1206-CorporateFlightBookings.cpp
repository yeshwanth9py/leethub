// Last updated: 6/11/2026, 11:29:21 AM
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& arr, int n) {
        vector<int> ans(n, 0);
        for(auto el: arr){
            int a = el[0];
            int b = el[1];
            int f = el[2];
            ans[a-1] += f;
            if(b<n) ans[b] -= f;
        }

        for(int i=1; i<n; i++){
            ans[i] += ans[i-1];
        }
        return ans;
    }
};