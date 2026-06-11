// Last updated: 6/11/2026, 11:28:34 AM
class Solution {
public:
    int dx[4] = {1, 0, 0, -1};
    int dy[4] = {0, -1, 1, 0};

    int minPushBox(vector<vector<char>>& arr) {
        int sx = -1;
        int sy = -1;
        int ex = -1;
        int ey = -1;
        int bx = -1;
        int by = -1;
        int n = arr.size();
        int m = arr[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(arr[i][j] == 'S'){
                    sx = i;
                    sy = j;
                }
                if(arr[i][j] == 'T'){
                    ex = i;
                    ey = j;
                }
                if(arr[i][j] == 'B'){
                    bx = i;
                    by = j;
                }
            }
        }

        int dist[21][21][21][21];
        memset(dist, 0x3f, sizeof(dist));

        dist[sx][sy][bx][by] = 0;
        deque<vector<int>> dq;
        dq.push_back({sx, sy, bx, by});

        while(!dq.empty()){
            auto tel = dq.front(); dq.pop_front();
            int cx = tel[0];
            int cy = tel[1];

            int cbx = tel[2];
            int cby = tel[3];

            for(int i=0; i<4; i++){
                int nx = cx+dx[i];
                int ny = cy+dy[i];
                if(nx<0 || ny<0 || nx>=n || ny>=m || arr[nx][ny] == '#') continue;

                if(nx == cbx && ny == cby){
                    int nbx = cbx+dx[i];
                    int nby = cby+dy[i];
                    if(nbx<0 || nby<0 || nbx>=n || nby>=m || arr[nbx][nby] == '#') continue;
                    if(nbx == ex && nby == ey) return dist[cx][cy][cbx][cby]+1;
                    if(dist[cbx][cby][nbx][nby]>dist[cx][cy][cbx][cby]+1){
                        dq.push_back({cbx, cby, nbx, nby});
                        dist[cbx][cby][nbx][nby] = dist[cx][cy][cbx][cby]+1;
                    }
                }else{
                    if(dist[nx][ny][cbx][cby]>dist[cx][cy][cbx][cby]){
                        dq.push_front({nx, ny, cbx, cby});
                        dist[nx][ny][cbx][cby] = dist[cx][cy][cbx][cby];
                    }
                }
            }
        }

        
        
        


        return -1;


    }
};