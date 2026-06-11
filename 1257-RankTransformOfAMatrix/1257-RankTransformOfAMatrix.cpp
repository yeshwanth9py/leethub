// Last updated: 6/11/2026, 11:29:10 AM
struct Unionfind{
    vector<long long> par;
    vector<long long> sz;
    long long noc;
    
    Unionfind(long long n){
        par.resize(n, 0);
        sz.resize(n, 1);
        noc = n;
        
        for(long long i=0; i<n; i++){
            par[i] = i;
        }
    }
    
    long long find(long long u){
        if(u == par[u]) return u;
        return par[u] = find(par[u]);
    }
    
    bool merge(long long u, long long v){
        u = find(u);
        v = find(v);
        
        if(u == v) return 0;
        if(sz[v]>=sz[u]) swap(u, v);
        
        sz[u] += sz[v];
        noc--;
        par[v] = u;
        return 1;
    }
};


class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();

        vector<vector<int>> vec;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                vec.push_back({arr[i][j], i, j});
            }
        }

        sort(vec.begin(), vec.end());

        vector<int> maxrow(n, 0);
        vector<int> maxcol(m, 0);
        
        vector<vector<int>> ans(n, vector<int>(m, 0));
        
        int i = 0;
        while(i<vec.size()){
            auto el = vec[i];
            int v = el[0];
            int x = el[1];
            int y = el[2];

            int j = i;

            Unionfind uf(n+m);

            while(j<vec.size() && vec[j][0] == vec[i][0]){
                int x = vec[j][1];
                int y = vec[j][2];
                uf.merge(x, y+n);
                j++;
            }

            unordered_map<int, int> ump;
            for(int k=i; k<j; k++){
                int r = vec[k][1];
                int c = vec[k][2];

                int root = uf.find(r);
                int curank = max(maxrow[r], maxcol[c])+1;

                if(ump.find(root) == ump.end()){
                    ump[root] = curank;
                }else{
                    ump[root] = max(ump[root], curank);
                }
            }

            for(int k=i; k<j; k++){
                int r = vec[k][1];
                int c = vec[k][2];
                int root = uf.find(r);
                ans[r][c] = ump[root];
                maxrow[r] = max(maxrow[r], ans[r][c]);
                maxcol[c] = max(maxcol[c], ans[r][c]);
            }

            i = j;
        }

        return ans;

    }
};