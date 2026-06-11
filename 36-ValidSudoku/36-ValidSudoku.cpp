// Last updated: 6/11/2026, 11:38:09 AM
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> cols(m, vector<int>(10, 0));
        vector<vector<int>> grid(9, vector<int>(10, 0));


        for(int i=0; i<n; i++){
            vector<int> row(10, 0);
            for(int j=0; j<m; j++){
                if(board[i][j] == '.') continue;
                int va = board[i][j] - '0';
                if(row[va]==1) return 0;
                if(cols[j][va] == 1) return 0;
                int rg = i/3;
                int cg = j/3;
                int gridno = rg*3 + cg;
                if(grid[gridno][va] == 1) return 0;
                row[va]++;
                cols[j][va]++;
                grid[gridno][va]++;
            }
        }


        return 1;


    }
};