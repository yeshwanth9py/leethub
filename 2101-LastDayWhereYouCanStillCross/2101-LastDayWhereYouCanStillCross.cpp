// Last updated: 6/11/2026, 11:25:02 AM
struct UnionFind{
    vector<int> par;
    vector<int> sz;
    UnionFind(int n){
        par.resize(n, 0);
        sz.resize(n, 1);
        for(int i=0; i<n; i++){
            par[i] = i;
        }
    }

    int find(int x){
        if(x == par[x]) return x;
        return par[x] = find(par[x]);
    }

    void merge(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return;
        if(sz[x]<=sz[y]) swap(x, y);
        sz[x] += sz[y];
        par[y] = x;
    }
};


class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int latestDayToCross(int r, int c, vector<vector<int>>& cells) {
        UnionFind uf(c*r+1);
        vector<vector<int>> arr(r+1, vector<int>(c+1, 0));

        for(int i=1; i<c; i++){
            uf.merge(i, i+1);
        }
            
        for(int i=1; i<c; i++){
            uf.merge((r-1)*c + i, (r-1)*c + i+1);
        }

        for(int i=cells.size()-1; i>=0; i--){
            int x = cells[i][0];
            int y = cells[i][1];
            arr[x][y] = 1;
            for(int j=0; j<4; j++){
                int nx = x+dx[j];
                int ny = y+dy[j];
                if(nx<=0 || ny<=0 || nx>r || ny>c) continue;
                if(arr[nx][ny] == 1){
                    uf.merge((nx-1)*c+ny, (x-1)*c + y);
                }
            }

            if(uf.find(1) == uf.find(r*c)) return i;
        }

        return 0;
    }
};