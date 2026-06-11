// Last updated: 6/11/2026, 11:28:38 AM
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int r = grid.size();
        int c = grid[0].size();

        if(k==0) return grid;

        vector<vector<int>> clone(grid.size(), vector<int>(grid[0].size(), -1));
        while(k--){
            for(int i=0; i<r; i++){
                for(int j=0; j<c; j++){
                    if(j!=c-1){
                        clone[i][j+1] = grid[i][j];
                    }else{
                        if(i==r-1){
                            clone[0][0] = grid[i][j];
                        }else{
                            clone[i+1][0] = grid[i][j];
                        }
                    }
                    
                }
            }

            grid = clone;
        }

        return clone;
    }
};