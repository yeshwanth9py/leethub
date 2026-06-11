// Last updated: 6/11/2026, 11:36:26 AM
class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> pascal(n+1, vector<int>(n, 0));
        vector<vector<int>> ans;
        for(int i=1; i<=n; i++){
            vector<int> temp;
            for(int j=0; j<i; j++){
                if(i == 1){
                    pascal[i][j] = 1;
                }else if(j == 0 || j == i-1){
                    pascal[i][j] = 1;
                }else{
                    pascal[i][j] = pascal[i-1][j] + pascal[i-1][j-1];
                }
                temp.push_back(pascal[i][j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};