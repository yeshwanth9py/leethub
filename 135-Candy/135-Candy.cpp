// Last updated: 6/11/2026, 11:35:57 AM
class Solution {
public:
    int candy(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, 1);
        for(int i=1; i<n; i++){
            if(arr[i]>arr[i-1] && ans[i]<=ans[i-1]){
                ans[i] += (ans[i-1]-ans[i])+1;
            }
        }

        for(int i=n-2; i>=0; i--){
            if(arr[i]>arr[i+1] && ans[i+1]>=ans[i]){
                ans[i] += (ans[i+1]-ans[i])+1;
            }
        }

        int anss = accumulate(ans.begin(), ans.end(), 0);
        return anss;
    }
};