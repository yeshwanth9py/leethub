// Last updated: 6/11/2026, 11:31:36 AM
class Solution {
public:
    vector<vector<int>> arr;
    int n,m;
    int dx[2] = {0, 1};
    int dy[2] = {1, 0};
    int dp[51][51][51][51];

    bool isvalid(int x, int y){
        if(x>=0 && y>=0 && x<n && y<m && arr[x][y] != -1) return 1;
        return 0;
    }

    int rec(int x1, int y1, int x2, int y2){
        if(x1 == n-1 && y1==m-1 && x2==n-1 && y2==m-1){
            return arr[x1][y1];
        }

        if(dp[x1][y1][x2][y2]!=-1) return dp[x1][y1][x2][y2];

        int add = arr[x1][y1] + arr[x2][y2];
        
        if(x1 == x2 && y1 == y2){
            add = arr[x1][y1];
        }


        int maxch = -1e9;
        for(int i=0; i<2; i++){
            for(int j=0; j<2; j++){
                int nx1 = x1+dx[i];
                int ny1 = y1+dy[i];
                int nx2 = x2+dx[j];
                int ny2 = y2+dy[j];
                if(isvalid(nx1, ny1) && isvalid(nx2, ny2)){
                    maxch = max(maxch, add+rec(nx1, ny1, nx2, ny2));
                }
            }
        }

        return dp[x1][y1][x2][y2] = maxch;
    }


    int cherryPickup(vector<vector<int>>& grid) {
        arr = grid;
        n = arr.size();
        m = arr[0].size();
        // cout<<n<<" "<<m;
        memset(dp, -1, sizeof(dp));
        int ans= rec(0, 0, 0, 0);
        return ((ans>=0)?ans:0);
    }
};