// Last updated: 6/11/2026, 11:17:22 AM
struct node{
    int time;
    int mv;
    int x;
    int y;
};

struct Compare{
    bool operator()(node a, node b){
        return a.time<b.time;
    }
};

class Solution {
public:
    int dx[4] = {1, 0, 0, -1};
    int dy[4] = {0, 1, -1, 0};
    int minTimeToReach(vector<vector<int>>& moveTime) {
        priority_queue<node, vector<node>, Compare> pq;
        int n = moveTime.size();
        int m = moveTime[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 2e9));
        dist[0][0] = 0;
        node root;
        root.time = 0;
        root.mv = 1;
        root.x = 0;
        root.y = 0;

        pq.push(root);
        while(!pq.empty()){
            auto tel = pq.top();
            pq.pop();
            int x = tel.x;
            int y = tel.y;
            if(dist[x][y]<-tel.time) continue;
            int cu = tel.mv;
            for(int i=0; i<4; i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
                if(dist[nx][ny] > max(moveTime[nx][ny], dist[x][y])+cu){
                    dist[nx][ny] = max(moveTime[nx][ny], dist[x][y])+cu;
                    node newnode;
                    newnode.x = nx;
                    newnode.y = ny;
                    newnode.mv = (cu)%2+1;
                    newnode.time = -dist[nx][ny];
                    pq.push(newnode);
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