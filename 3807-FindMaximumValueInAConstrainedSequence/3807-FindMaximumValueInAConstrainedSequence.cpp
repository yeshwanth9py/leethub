// Last updated: 6/11/2026, 11:15:37 AM
class Solution {
public:
    vector<int> arr;
    int findMaxVal(int n, vector<vector<int>>& rest, vector<int>& diff) {
        arr.resize(n, 1e9);
        for(auto el: rest){
            int idx = el[0];
            int val = el[1];
            arr[idx] = val;
        }
        
        arr[0] = 0;
        for(int i=1; i<n; i++){
            arr[i] = min(arr[i-1]+diff[i-1], arr[i]);
        }

        for(int i=n-2; i>=0; i--){
            arr[i] = min(arr[i], arr[i+1]+diff[i]);
        }

        return *max_element(arr.begin(), arr.end());

    }
};