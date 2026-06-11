// Last updated: 6/11/2026, 11:14:44 AM
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

    void merge(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return;
        if(sz[y]>=sz[x]) swap(x, y);
        sz[x] += sz[y];
        par[y] = x;
    }
};

class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        sort(edges.begin(), edges.end(), [&](vector<int> &a, vector<int> &b){
            if(a[3] != b[3]) return a[3]>b[3];
            return a[2]>b[2];
        });

        int tot = n;
        Unionfind uf(n);
       
        int rem = k;
        vector<int> ans;
        int anstn = 1e9;
        for(auto el: edges){
            int u = el[0];
            int v = el[1];
            int s = el[2];
            cout<<u<<" "<<v<<endl;;
            int ty = el[3];
            if(uf.find(u) == uf.find(v)){
                if(ty) return -1;
                continue;
            }

            else if(ty){
                uf.merge(u, v);
                tot--;
                anstn = min(anstn, s);
            }else{
                ans.push_back(s);
                uf.merge(u, v);
                tot--;
            }
        }
        if(tot != 1) return -1;
        for(int i=ans.size()-1; i>=0; i--){
            if(rem>0){
                rem--;
                int curs = ans[i]*2;
                anstn = min(anstn, curs);
            }else{
                anstn = min(anstn, ans[i]);
            }
        }

        return anstn;
    }
};