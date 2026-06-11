// Last updated: 6/11/2026, 11:36:02 AM
class Solution {
public:
    bool isvalid(int x, int y, int n, int m){
        return x>=0 && y>=0 && x<n && y<m;
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if((i==0 || j==0 || i==n-1 || j==m-1) && board[i][j] == 'O'){
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
        int dx[4] = {1, 0, 0, -1};
        int dy[4] = {0, -1, 1, 0};

        while(!q.empty()){
            auto [x, y]= q.front();
            q.pop();
            board[x][y] = 'z';

            for(int i=0; i<4; i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(isvalid(nx, ny, n, m) && vis[nx][ny]==0 && board[nx][ny] == 'O'){
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }else if(board[i][j] == 'z'){
                    board[i][j] = 'O';
                }
            }
        }




    }
};