// Last updated: 6/11/2026, 11:29:35 AM
class Solution {
public:
    int n, m;
    vector<vector<int>> vis;
    vector<vector<int>> arr;
    int dfs(int r, int c, int fcol, int tcol){
        if(r<0 || r>=n || c<0 || c>=m){
            return 1;
        }
        if(vis[r][c] == 1) return 0;

        if((arr[r][c] != fcol)){
            return 1;
        }

        vis[r][c] = 1;
        int top = dfs(r-1, c, fcol, tcol);
        int bot = dfs(r+1, c, fcol, tcol);
        int left = dfs(r, c-1, fcol, tcol);
        int right = dfs(r, c+1, fcol, tcol);

        int ans = (top || bot || left || right);
        if(ans){
            arr[r][c] = tcol;
        }

        return 0;
    }


    vector<vector<int>> colorBorder(vector<vector<int>>& arrr, int r, int c, int col) {
        arr = arrr;
        n = arr.size();
        m = arr[0].size();

        vis.resize(n, vector<int>(m, 0));

        dfs(r, c, arr[r][c], col);

        return arr;

    }
};

