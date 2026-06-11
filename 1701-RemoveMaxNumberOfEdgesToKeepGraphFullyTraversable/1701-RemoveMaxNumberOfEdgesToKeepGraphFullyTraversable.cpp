// Last updated: 6/11/2026, 11:26:53 AM
struct Unionfind{
    vector<int> par;
    vector<int> sz;
    int noc;
    Unionfind(int n){
        par.resize(n, 0);
        sz.resize(n, 1);
        for(int i=0; i<n; i++){
            par[i] = i;
        }
        noc = n;
    }

    int find(int x){
        if(par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    bool merge(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return 0;
        if(sz[y]>=sz[x]) swap(x, y);
        sz[x] += sz[y];
        noc--;
        par[y] = x;
        return 1;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        Unionfind uf(n);

        vector<vector<int>> edg1;
        vector<vector<int>> edg2;

        int used = 0;
        for(auto el: edges){
            int ty = el[0];
            int u = el[1];
            int v = el[2];
            u--;
            v--;
            if(ty == 1){
                edg1.push_back({u, v});
            }else if(ty == 2){
                edg2.push_back({u, v});
            }else{
                if(uf.merge(u, v)){
                    used++;
                    cout<<3<<" "<<u+1<<" "<<v+1<<endl;
                    if(uf.noc == 1){
                        return edges.size()-used;
                    }
                }
            }
        }

        auto uf2 = uf;

        for(auto el: edg1){
            int u = el[0];
            int v = el[1];
            if(uf.merge(u, v)){
                used++;
                cout<<1<<" "<<u+1<<" "<<v+1<<endl;
                if(uf.noc == 1){
                    break;
                }
            }
        }

        for(auto el: edg2){
            int u = el[0];
            int v = el[1];
            if(uf2.merge(u, v)){
                used++;
                cout<<2<<" "<<u+1<<" "<<v+1<<endl;
                if(uf2.noc == 1){
                    break;
                }
            }
        }

        if(uf.noc == 1 && uf2.noc == 1) return edges.size()-used;
        
        return -1;
    }
};