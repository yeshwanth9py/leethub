// Last updated: 6/11/2026, 11:37:48 AM
class Solution {
public:
    int n;
    int m;
    void rotate(vector<vector<int>>& arr) {
        n = arr.size();
        m = arr[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                swap(arr[i][j], arr[j][i]);
            }
        }

        for(int i=0; i<n; i++){
            int j1 = 0;
            int j2 = m-1;
            while(j1<j2){
                swap(arr[i][j1], arr[i][j2]);
                j1++;
                j2--;
            }
        }

        // return arr;
    }
};