// Last updated: 6/11/2026, 11:37:56 AM
class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        vector<int> nge(n, -1);
        vector<int> pge(n, -1);
        nge[n-1] = n-1;
        for(int i=n-2; i>=0; i--){
            if(arr[nge[i+1]]>arr[i]){
                nge[i] = nge[i+1];
            }else{
                nge[i] = i;
            }
        }

        pge[0] = 0;
        for(int i=1; i<n; i++){
            if(arr[pge[i-1]] > arr[i]){
                pge[i] = pge[i-1];
            }else{
                pge[i] = i;
            }
        }

        int ans = 0;
        for(int i=1; i<n-1; i++){
            int pg = pge[i];
            int ng = nge[i];
            if(pg == i || i == ng) continue;
            int area = min(arr[pg], arr[ng]) - arr[i];
            ans += (area);
        }

        return ans;
    }
};