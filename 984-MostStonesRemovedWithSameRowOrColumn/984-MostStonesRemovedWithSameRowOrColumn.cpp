// Last updated: 6/11/2026, 11:30:13 AM
struct Unionfind{
    vector<int> sz;
    vector<int> par;
    int n;
    Unionfind(int n){
        sz.resize(n, 1);
        par.resize(n, -1);
        this->n = n;
        for(int i=0; i<n; i++) par[i] = i;
    }

    int find(int x){
        if(x == par[x]) return x;
        return par[x] = find(par[x]);
    }

    void merge(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b) return;
        if(sz[b]>=sz[a]) swap(a, b);
        sz[a] += sz[b];
        par[b] = a; 
    }

    int findlar(){
        int ans = 0;
        for(int i=0; i<n; i++){
            if(par[i] == i){
                // cout<<i<<" "<<sz[i]<<"\n";
                ans += (sz[i]-1);
            }
        }
        return ans;
    }
};


class Solution {
public:
    unordered_map<int, vector<int>> umpx;
    unordered_map<int, vector<int>> umpy;
    map<pair<int, int>, int> mp;
    int removeStones(vector<vector<int>>& arr) {
        int n = arr.size();
        int id = 0;
        for(auto el: arr){
            int x = el[0];
            int y = el[1];
            umpx[x].push_back(y);
            umpy[y].push_back(x);
            mp[{x, y}] = id;
            id++;
        }
        Unionfind uf(n);

        for(auto el: umpx){
            int x = el.first;
            int y = el.second[0];
            int fp = mp[{x, y}];
            for(int j=1; j<el.second.size(); j++){
                int sy = el.second[j];
                int sp = mp[{x, sy}];
                uf.merge(fp, sp);
            }
        }

        for(auto el: umpy){
            int y = el.first;
            int x = el.second[0];
            int fp = mp[{x, y}];
            for(int j=1; j<el.second.size(); j++){
                int sx = el.second[j];
                int sp = mp[{sx, y}];
                uf.merge(fp, sp);
            }
        }
        
        return uf.findlar();
    }
};







