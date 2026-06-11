// Last updated: 6/11/2026, 11:23:04 AM
class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> vis(m, vector<int>(n, 0));

        for(auto vec: walls){
            int x = vec[0];
            int y = vec[1];
            vis[x][y] = 2;  //blocked
        }

        queue<vector<int>> q;

        //1 2 3 4

        for(auto vec: guards){
            int x = vec[0];
            int y = vec[1];
            vis[x][y] = 2;  //blocked
            q.push({x, y, 1});
            q.push({x, y, 2});
            q.push({x, y, 3});
            q.push({x, y, 4});
        }

        while(!q.empty()){
            auto vec = q.front(); q.pop();
            int x = vec[0];
            int y = vec[1];
            int dir = vec[2];

            int nx = x;
            int ny = y;
            if(dir == 1){
                nx--;
            }else if(dir == 2){
                ny++;
            }else if(dir == 3){
                nx++;
            }else{
                ny--;
            }

            if(nx<0 || ny<0 || nx>=m || ny>=n || vis[nx][ny] == 2) continue;
            q.push({nx, ny, dir});
            vis[nx][ny] = 1;
        }

        int cnt = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(vis[i][j] == 0) cnt++;
            }
        }

        return cnt;
    }
};