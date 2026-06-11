// Last updated: 6/11/2026, 11:27:51 AM
class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    int minCost(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;
        deque<pair<int, int>> q;
        q.push_back({0, 0});
        while(!q.empty()){
            auto [x, y] = q.front(); q.pop_front();
            for(int i=0; i<4; i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
                int cos = (((i+1) == arr[x][y])?0:1);
                if(dist[nx][ny] > dist[x][y] + cos){
                    dist[nx][ny] = dist[x][y] + cos;
                    if(cos){
                        q.push_back({nx, ny});
                    }else{
                        q.push_front({nx, ny});
                    }
                }
            }
        }

        return dist[n-1][m-1];






    }
};