// Last updated: 6/11/2026, 11:21:08 AM
class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int minimumTime(vector<vector<int>>& arr) {
        long long n = arr.size();
        long long m = arr[0].size();
        if(arr[0][1]>1 && arr[1][0]>1) return -1;

        vector<vector<long long>> dist(n, vector<long long>(m, 1e18));
        dist[0][0] = 0;

        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>> > pq;
        pq.push({0, 0, 0});

        while(!pq.empty()){
            auto tn = pq.top(); pq.pop();
            long long curd = tn[0];
            long long x = tn[1];
            long long y = tn[2];
            for(long long i=0; i<4; i++){
                long long nx = x+dx[i];
                long long ny = y+dy[i];
                if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
                int updt = dist[x][y]+1;
                
                if(arr[nx][ny]>updt){
                    int dif = arr[nx][ny] - updt;
                    int cnt = (dif+1)/2;
                    updt += 2*cnt;
                }

                if(dist[nx][ny]>updt){
                    dist[nx][ny] = updt;
                    pq.push({dist[nx][ny], nx, ny});
                }
            }
        } 

        if(dist[n-1][m-1] >= 1e17) return -1;

        return dist[n-1][m-1];
    }
};



