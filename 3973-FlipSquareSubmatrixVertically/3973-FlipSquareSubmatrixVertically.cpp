// Last updated: 6/11/2026, 11:14:23 AM
class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& arr, int x, int y, int k) {
        int n = arr.size();
        int m = arr[0].size();
        for(int j=y; j<y+k; j++){
            int ii = x+k-1;
            for(int i=x; i<ii; i++){
                // cout<<arr[i][j]<<" "<< arr[ii][j]<<endl;
                swap(arr[i][j], arr[ii][j]);
                ii--;
            }
        }

        return arr;
    }
};