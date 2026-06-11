// Last updated: 6/11/2026, 11:26:08 AM
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        queue<pair<int, int>> q;
        int r = isWater.size();
        int c = isWater[0].size();
        vector<vector<int>> vis(r, vector<int> (c, 0));
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(isWater[i][j] == 1){
                    q.push({i, j});
                    isWater[i][j] = 0;
                    vis[i][j] = 1;
                }
            }
        }

        int dx[4] = {1, 0, 0, -1};
        int dy[4] = {0, -1, 1, 0};

        while(!q.empty()){
            auto el = q.front();
            q.pop();
            int cx = el.first;
            int cy = el.second;
            int h = isWater[cx][cy];
            for(int i=0; i<4; i++){
                int nx = cx+dx[i];
                int ny = cy+dy[i];
                if(nx<0 || ny<0 || nx>=r || ny>=c || vis[nx][ny] == 1){
                    continue;
                }
                isWater[nx][ny] = h+1;
                q.push({nx, ny});
                vis[nx][ny] = 1;
            }
        }

        return isWater;


    }
};