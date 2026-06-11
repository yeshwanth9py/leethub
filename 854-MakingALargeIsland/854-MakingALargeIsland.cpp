// Last updated: 6/11/2026, 11:30:51 AM
struct Unionfind{
    vector<int> sz;
    vector<int> par;
    int maxsiz;
    stack<vector<int>> st;
    Unionfind(int n){
        sz.resize(n, 1);
        par.resize(n, 1);
        for(int i=0; i<n; i++){
            par[i] = i; 
        }
        maxsiz = 1;
    }  

    int find(int x){
        if(x == par[x]) return x;
        return find(par[x]);
    }

    bool merge(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return 0;
        if(sz[y]>=sz[x]) swap(x, y);
        int pary = par[y];
        st.push({y, pary, x, maxsiz});
        sz[x] += sz[y];
        maxsiz = max(maxsiz, sz[x]);
        par[y] = x;
        return 1;
    }

    void undo(){
        vector<int> vec = st.top(); st.pop();
        int y = vec[0];
        int y1 = vec[1];
        int x = vec[2];
        par[y] = y1;
        sz[x] -= sz[y];
        maxsiz = vec[3];
    }
};

class Solution {
public:
    int n;
    int m;
    int largestIsland(vector<vector<int>>& arr) {
        n = arr.size();
        m = arr[0].size();
        int tot = n*m;
        Unionfind uf(tot);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(arr[i][j] == 1){
                    int cur = i*m + j;
                    if(i-1>=0 && arr[i-1][j] == 1){
                        int pcur = (i-1)*m + j;
                        uf.merge(cur, pcur);
                    }
                    if(i+1<n && arr[i+1][j] == 1){
                        int pcur = (i+1)*m + j;
                        uf.merge(cur, pcur);
                    }
                    if(j-1>=0 && arr[i][j-1] == 1){
                        int pcur = (i)*m + j-1;
                        uf.merge(cur, pcur);
                    }
                    if(j+1<m && arr[i][j+1] == 1){
                        int pcur = (i)*m + j+1;
                        uf.merge(cur, pcur);
                    }
                }
            }
        }

        int ans = uf.maxsiz;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(arr[i][j] == 0){
                    int pssz = uf.st.size();
                    int cur = i*m + j;
                    if(i-1>=0 && arr[i-1][j] == 1){
                        int pcur = (i-1)*m + j;
                        uf.merge(cur, pcur);
                    }
                    if(i+1<n && arr[i+1][j] == 1){
                        int pcur = (i+1)*m + j;
                        uf.merge(cur, pcur);
                    }
                    if(j-1>=0 && arr[i][j-1] == 1){
                        int pcur = (i)*m + j-1;
                        uf.merge(cur, pcur);
                    }
                    if(j+1<m && arr[i][j+1] == 1){
                        int pcur = (i)*m + j+1;
                        uf.merge(cur, pcur);
                    }

                    ans = max(ans, uf.maxsiz);

                    int cssz = uf.st.size();
                    int dif = cssz - pssz;
                    while(dif--){
                        uf.undo();
                    }
                }
            }
        }

        return ans;

    }
};