// Last updated: 6/11/2026, 11:32:37 AM
class Solution {
public:
    bool isvalid(int r, int c, int n, int m){
        return (r>=0 && c>=0 && r<n && c<m);
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int n = mat.size();
        int m = mat[0].size();
        // int dist[n+1][m+1] = {1e9};
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0){
                    pq.push({0, {i, j}});
                    dist[i][j] = 0;
                }
            }
        }

        int newr[4] = {1, 0, -1, 0};
        int newc[4] = {0, 1, 0, -1};

        while(!pq.empty()){
            auto cn = pq.top();
            pq.pop();
            for(int i=0; i<4; i++){
                int nr = cn.second.first+newr[i];
                int nc = cn.second.second+newc[i];
                if(isvalid(nr, nc, n, m) && dist[nr][nc]>dist[cn.second.first][cn.second.second]+1){
                    dist[nr][nc] = dist[cn.second.first][cn.second.second]+1;
                    pq.push({dist[nr][nc], {nr, nc}});
                }
            }

        }

        return dist;



        




        


    }
};