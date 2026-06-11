// Last updated: 6/11/2026, 11:28:55 AM
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        int mind = 1e9;

        int n = arr.size();
        sort(arr.begin(), arr.end());
        for(int i=0; i<n-1; i++){
            int d = arr[i+1]-arr[i];
            if(d<mind){
                mind = d;
                ans.clear();
                ans.push_back({arr[i], arr[i+1]});
            }else if(d == mind){
                ans.push_back({arr[i], arr[i+1]});
            }
        }

        return ans;
    }
};