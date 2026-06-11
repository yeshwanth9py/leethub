// Last updated: 6/11/2026, 11:17:23 AM
class Solution {
public:
    int n, m;
    int dx[4] = {1, 0, 0, -1};
    int dy[4] = {0, -1, 1, 0};
    int minTimeToReach(vector<vector<int>>& arr) {
        n = arr.size();
        m = arr[0].size();
        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({0, {0, 0}});
        vector<vector<int>> dist(n, vector<int>(m, 2e9));
        dist[0][0] = 0;
        while(!pq.empty()){
            auto tel = pq.top();
            pq.pop();
            int x = tel.second.first;
            int y = tel.second.second;
            if(dist[x][y]<-tel.first) continue;
            if(x == n-1 && y == m-1) return dist[n-1][m-1];
            for(int i=0; i<4; i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
                if(dist[nx][ny]>dist[x][y]+1){
                    if(arr[nx][ny]<=dist[x][y]){
                        dist[nx][ny] = dist[x][y]+1LL;
                    }else{
                        dist[nx][ny] = arr[nx][ny]+1LL;
                    }
                    if(x == n-1 && y == m-1) return dist[n-1][m-1];
                    pq.push({-dist[nx][ny], {nx, ny}});
                }
            }
        }

        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         cout<<dist[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        return dist[n-1][m-1];

    }
};