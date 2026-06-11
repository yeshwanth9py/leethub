// Last updated: 6/11/2026, 11:27:31 AM
class Solution {
public:
    int n, m; 
    vector<vector<int>> arr;
    int dy[3] = {-1, 0, 1};
    int dp[71][71][71];

    bool isvalid(int x, int y){
        if(x>=0 && x<n && y>=0 && y<m) return 1;
        return 0;
    }

    int rec(int x1, int y1, int x2, int y2){
        if(isvalid(x1, y1) == 0 || isvalid(x2, y2) == 0){
            return -1e9;
        }

        if(x1 == n-1){
            int add = arr[x1][y1] + arr[x2][y2];
        
            if(x1 == x2 && y1 == y2){
                add = arr[x1][y1];
            }
            return add;
        }

        int add = arr[x1][y1] + arr[x2][y2];
        
        if(x1 == x2 && y1 == y2){
            add = arr[x1][y1];
        }
        
        if(dp[x1][y1][y2]!=-1) return dp[x1][y1][y2];

        int nx1 = x1+1;
        int nx2 = x2+1;

        int maxch = -1e9;

        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                int ny1 = y1+dy[i];
                int ny2 = y2+dy[j];
                maxch = max(maxch, add+rec(nx1, ny1, nx2, ny2));
            }
        }

        return dp[x1][y1][y2] = maxch;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        memset(dp, -1, sizeof(dp));

        arr = grid;
        return rec(0, 0, 0, m-1);
    }
};