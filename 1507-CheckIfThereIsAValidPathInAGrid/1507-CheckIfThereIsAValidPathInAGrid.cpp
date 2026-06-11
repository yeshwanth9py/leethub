// Last updated: 6/11/2026, 11:27:47 AM
class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // For each street type, store allowed directions:
        // left, right, up, down
        vector<vector<pair<int,int>>> dirs(7);

        dirs[1] = {{0,-1}, {0,1}};    // left-right
        dirs[2] = {{-1,0}, {1,0}};    // up-down
        dirs[3] = {{0,-1}, {1,0}};    // left-down
        dirs[4] = {{0,1}, {1,0}};     // right-down
        dirs[5] = {{0,-1}, {-1,0}};   // left-up
        dirs[6] = {{0,1}, {-1,0}};    // right-up

        vector<vector<int>> vis(m, vector<int>(n, 0));

        queue<pair<int,int>> q;
        q.push({0,0});
        vis[0][0] = 1;

        while(!q.empty()) {
            auto [x,y] = q.front();
            q.pop();

            if(x == m-1 && y == n-1)
                return true;

            // Try all roads current cell can go to
            for(auto [dx,dy] : dirs[grid[x][y]]) {

                int nx = x + dx;
                int ny = y + dy;

                if(nx < 0 || ny < 0 || nx >= m || ny >= n)
                    continue;

                if(vis[nx][ny])
                    continue;

                // Check if neighbor has a road back to current
                bool validConnection = false;

                for(auto [backx, backy] : dirs[grid[nx][ny]]) {
                    if(nx + backx == x && ny + backy == y) {
                        validConnection = true;
                        break;
                    }
                }

                if(validConnection) {
                    vis[nx][ny] = 1;
                    q.push({nx,ny});
                }
            }
        }

        return false;
    }
};