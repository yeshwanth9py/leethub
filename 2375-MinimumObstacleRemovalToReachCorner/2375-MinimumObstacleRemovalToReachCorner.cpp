// Last updated: 6/11/2026, 11:22:59 AM
class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
 
    int minimumObstacles(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        
        deque<pair<int, int>> dq;
        dq.push_back({0, 0});
        dist[0][0] = 0;
        
        while(!dq.empty()){
            auto [x, y] = dq.front(); dq.pop_front();
            for(int i=0; i<4; i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
                int cost = (arr[nx][ny]);
                
                if(dist[nx][ny] > dist[x][y] + cost){
                    dist[nx][ny] = dist[x][y] + cost;
                    if(cost){
                        dq.push_back({nx, ny});
                    }else{
                        dq.push_front({nx, ny});
                    }
                }
            }
        }
        
        return dist[n-1][m-1];
    }
};