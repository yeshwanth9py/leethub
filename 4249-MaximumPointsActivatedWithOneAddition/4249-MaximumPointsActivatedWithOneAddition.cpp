// Last updated: 6/11/2026, 11:10:06 AM
struct Unionfind{
    vector<int> par;
    vector<int> sz;
    int n;
    Unionfind(int n){
        par.resize(n, 0);
        sz.resize(n, 1);
        this->n = n;
        for(int i=0; i<n; i++){
            par[i] = i;
        }
    }

    int find(int x){
        if(x == par[x]) return x;
        return par[x] = find(par[x]);
    }

    void merge(int u, int v){
        u = find(u);
        v = find(v);
        if(u == v) return;
        if(sz[v]>=sz[u]) swap(u, v);
        sz[u] += sz[v];
        par[v] = u;
    }

    int findmaxp(){
        int maxs1 = 0;
        int maxs2 = 0;
        for(int i=0; i<n; i++){
            int cur = find(i);
            if(i != cur) continue;
            // cout<<sz[cur]<<" ";
            if(sz[cur]>=maxs1){
                maxs2 = maxs1;
                maxs1 = sz[cur];
            }else if(sz[cur]>=maxs2){
                maxs2 = sz[cur];
            }
        }
        // cout<<endl;
        // cout<<maxs1<<" "<<maxs2<<endl;
        return maxs1+maxs2+1;
    }

};



class Solution {
public:
    unordered_map<int, int> cmpx;
    unordered_map<int, int> cmpy;
    int totx;
    int toty;

    vector<vector<int>> adjlx;
    vector<vector<int>> adjly;

    map<pair<int, int>, int> idofpoi;

    int maxActivated(vector<vector<int>>& points) {
        if(points.size() == 1) return 2;
        for(auto el: points){
            int x = el[0];
            int y = el[1];
            cmpx[x] = 1;
            cmpy[y] = 1;
        }

        int id = 0;
        for(auto el: cmpx){
            int x = el.first;
            cmpx[x] = id;
            id++;
        }

        totx = id;
        id = 0;

        for(auto el: cmpy){
            int y = el.first;
            cmpy[y] = id;
            id++;
        }

        toty = id;

        adjlx.resize(totx+5, vector<int>());
        adjly.resize(toty+5, vector<int>());

        id = 0;
        for(auto el: points){
            int x = cmpx[el[0]];
            int y = cmpy[el[1]];
            adjlx[x].push_back(y);
            adjly[y].push_back(x);
            idofpoi[{x, y}] = id;
            id++;
        }

        Unionfind uf(points.size());

        for(int i=0; i<adjlx.size(); i++){
            int x = i;
            if(adjlx[x].size() <= 1) continue;
            int sy = adjlx[x][0];
            int po = idofpoi[{x, sy}];
            for(int j=1; j<adjlx[x].size(); j++){
                int y = adjlx[x][j];
                int curpo = idofpoi[{x, y}];
                uf.merge(po, curpo);
            }
        }

        for(int i=0; i<adjly.size(); i++){
            int y = i;
            if(adjly[y].size() <= 1) continue;
            int sx = adjly[y][0];
            int po = idofpoi[{sx, y}];
            for(int j=1; j<adjly[y].size(); j++){
                int x = adjly[y][j];
                int curpo = idofpoi[{x, y}];
                uf.merge(po, curpo);
            }
        }

        int ans =  uf.findmaxp();
        return min(ans, (int) points.size()+1);
    }
};