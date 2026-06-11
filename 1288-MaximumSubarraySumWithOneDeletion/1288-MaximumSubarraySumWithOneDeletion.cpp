// Last updated: 6/11/2026, 11:29:03 AM
class Solution {
public:
    int n;
    int maximumSum(vector<int>& arr) {
        n = arr.size();
        vector<int> maxend(n, -1e9);
        vector<int> maxstart(n, -1e9);
        int cs = 0;
        int mx = -1e9;
        int ans = arr[0];
        for(int i=0; i<n; i++){
            cs += arr[i];
            mx = max(mx, cs);
            maxend[i] = cs;
            ans = max(ans, mx);
            if(cs<0){
                cs = 0;
            }
        }
        cs = 0;
        mx = -1e9;
        for(int i=n-1; i>=0; i--){
            cs += arr[i];
            mx = max(mx, cs);
            ans = max(ans, mx);
            maxstart[i] = cs;
            if(cs<0) cs = 0;
        }

        // for(int i=0; i<n; i++){
        //     cout<<maxstart[i]<<" ";
        // }
        // cout<<endl;

        // for(int i=0; i<n; i++){
        //     cout<<maxend[i]<<" ";
        // }
        // cout<<endl;

        for(int i=0; i<n; i++){
            int cur = maxend[i] + ((i+2<n)?maxstart[i+2]:0);
            ans = max(ans, cur);
        }

        return ans;
    }
};