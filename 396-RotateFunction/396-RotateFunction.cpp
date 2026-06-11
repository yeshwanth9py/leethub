// Last updated: 6/11/2026, 11:33:23 AM
class Solution {
public:
    int maxRotateFunction(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        int ts = 0;
        for(int i=0; i<n; i++){
            ans += i*(arr[i]);
            ts += arr[i];
        }
        int bans = ans;
        for(int i=n-1; i>=0; i--){
            int cur = (n-1)*arr[i];
            ans -= cur;
            ans += (ts-arr[i]);
            bans = max(bans, ans);
        }

        return bans;

    }
};