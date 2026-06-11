// Last updated: 6/11/2026, 11:26:50 AM
struct Unionfind{
    vector<int> par;
    vector<int> sz;
    Unionfind(int n){
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

    void merge(int u, int v){
        u = find(u);
        v = find(v);
        if(u == v) return;
        if(sz[v]>=sz[u]) swap(u, v);
        sz[u] += sz[v];
        par[v] = u;
    }
};


class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& p) {
        int n = p.size();
        Unionfind uf(n);
        int cost = 0;

        vector<vector<int>> temp;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int d = abs((p[i][0] - p[j][0])) + abs(p[i][1] - p[j][1]);
                temp.push_back({d, i, j});
            }
        }

        sort(temp.begin(), temp.end());
        for(int j=0; j<temp.size(); j++){
            int el = temp[j][1];
            int i = temp[j][2];
            int c = temp[j][0];
            if(uf.find(el)!=uf.find(i)){
                uf.merge(i, el);
                cost += c;
            }
        }

        return cost;


    }
};