// Last updated: 6/11/2026, 11:19:20 AM
class Solution {
public:
    int dup = -1;
    int miss = -1;
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                double val = abs(grid[i][j]) - 1;
                int r = val / n;
                int c = (int)val % m;
                if (grid[r][c] < 0) {
                    dup = abs(grid[i][j]);
                } else {
                    grid[r][c] = -grid[r][c];
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0) {
                    miss = (i * n) + j + 1;
                }
            }
        }

        return {dup, miss};
    }
};