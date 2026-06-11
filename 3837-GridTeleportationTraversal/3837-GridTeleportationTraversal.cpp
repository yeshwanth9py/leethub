// Last updated: 6/11/2026, 11:15:17 AM
struct node{
    int x, y;
    // vector<int> portal;
};

class Solution {
public:
    int n,m; 
    int dist[1001][1001];
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    vector<vector<pair<int, int>>> ump;

    int minMoves(vector<string>& mat) {
        n = mat.size(); m = mat[0].size();
        ump.resize(26, vector<pair<int, int>>());
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                // cout<<mat[i][j]<<" ";
                if(mat[i][j]>='A' && mat[i][j]<='Z'){
                    ump[mat[i][j]-'A'].push_back({i, j});
                }
                dist[i][j] = 1e9;
            }
            // cout<<endl;
        }
        // cout<<endl;

        dist[0][0] = 0;
        deque<node> dq;
        vector<int> isp(26, 0);

        dq.push_back({0, 0});

        while(!dq.empty()){
            auto nd = dq.front(); dq.pop_front();
            int x = nd.x;
            int y = nd.y;
            // vector<int> isp = nd.portal;

            for(int i=0; i<4; i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx<0 || ny<0 || nx>=n || ny>=m || mat[nx][ny] == '#') continue;
                if(dist[nx][ny]>dist[x][y]+1){
                    dist[nx][ny]=dist[x][y]+1;
                    dq.push_back({nx, ny});
                }
            }

            //if portal is possible from here
            if(mat[x][y] >= 'A' && mat[x][y] <= 'Z' && isp[mat[x][y]-'A'] == 0){
                for(auto [nx, ny]: ump[mat[x][y]-'A']){
                    if(dist[nx][ny]>dist[x][y]){
                        dist[nx][ny] = dist[x][y];
                        isp[mat[x][y]-'A'] = 1;
                        dq.push_front({nx, ny});
                    }
                }
            }
        }

        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         cout<<dist[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        int ans = dist[n-1][m-1];
        if(ans<1e9) return ans;
        return -1;
    }
};