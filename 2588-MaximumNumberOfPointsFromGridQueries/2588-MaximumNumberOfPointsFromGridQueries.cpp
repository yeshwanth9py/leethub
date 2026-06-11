// Last updated: 6/11/2026, 11:21:47 AM
class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        set<int> us(queries.begin(), queries.end());
        priority_queue<pair<int, pair<int, int>>> pq;
        int n = grid.size();
        int m = grid[0].size();
        int dx[4] = {1, 0, 0, -1};
        int dy[4] = {0, -1, 1, 0};
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        pq.push({-grid[0][0], {0, 0}});
        vis[0][0] = 1;
        int cnt = 0;
        unordered_map<int, int> ans;
        vector<int> actans;
        for(int el: us){
            while(!pq.empty()){
                auto cn = pq.top();
                pq.pop();
                int cx = cn.second.first;
                int cy = cn.second.second;
                if(grid[cx][cy]>=el){
                    pq.push({-grid[cx][cy], {cx, cy}});
                    break;
                }
                cnt++;
                for(int i=0; i<4; i++){
                    int nx = cx+dx[i];
                    int ny = cy+dy[i];
                    if(nx<0 || ny<0 || nx>=n || ny>= m || vis[nx][ny] == 1){
                        continue;
                    }
                    vis[nx][ny] = 1;
                    pq.push({-grid[nx][ny], {nx, ny}});
                }
            }
            ans[el] = cnt;
        }

        for(int q: queries){
            actans.push_back(ans[q]);
        }

        return actans;
    }
};