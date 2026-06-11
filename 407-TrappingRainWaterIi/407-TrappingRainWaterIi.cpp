// Last updated: 6/11/2026, 11:33:14 AM
class Solution {
public:
    int trapRainWater(vector<vector<int>>& hm) {
        int n = hm.size();
        int m = hm[0].size();
        if(n<3 || m<3) return 0;

        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > pq;

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i=0; i<m; i++){
            pq.push({hm[0][i], {0, i}});
            pq.push({hm[n-1][i], {n-1, i}});
            vis[0][i] = 1;
            vis[n-1][i] = 1;
        }

        for(int i=0; i<n; i++){
            pq.push({hm[i][0], {i, 0}});
            pq.push({hm[i][m-1], {i, m-1}});
            vis[i][0] = 1;
            vis[i][m-1] = 1;
        }

        auto isvalid = [&](int x, int y){
            if(x<0 || y<0 || x>=n || y>=m || vis[x][y] == 1) return 0;
            return 1;
        };

        int ans = 0;
        int level = 0;
        while(!pq.empty()){
            auto tel = pq.top(); pq.pop();
            int ch = tel.first;
            level = max(ch, level);
            int x = tel.second.first;
            int y = tel.second.second;

            for(int i=0; i<4; i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(!isvalid(nx, ny)) continue;
                if(hm[nx][ny] < level){
                    ans += (level-hm[nx][ny]);
                    pq.push({hm[nx][ny], {nx, ny}});
                    vis[nx][ny] = 1;
                }else{
                    pq.push({hm[nx][ny], {nx, ny}});
                    vis[nx][ny] = 1;
                }
            }
        }

        return ans;
    }
};