// Last updated: 6/11/2026, 11:10:38 AM
struct Seg{
    vector<int> t;
    Seg(int n, vector<int> &arr){
        t.resize(4*n, 0);
        build(1, 0, n-1, arr);
    }
    void build(int idx, int l, int r, vector<int> &arr){
        if(l == r){
            t[idx] = (arr[l]);
            return;
        }
        int mid = (l+r)/2;
        build(2*idx, l, mid, arr);
        build(2*idx+1, mid+1, r, arr);
        t[idx] = t[2*idx] ^ t[2*idx+1];
    }

    void update(int idx, int l, int r, int pos, int v){
        if(pos<l || pos>r) return;
        if(l == r){
            t[idx] = v;
            return;
        }
        int mid = (l+r)/2;
        update(2*idx, l, mid, pos, v);
        update(2*idx+1, mid+1, r, pos, v);
        t[idx] = t[2*idx] ^ t[2*idx+1];
    }

    int query(int idx, int l, int r, int ql, int qr){
        if(r<ql || l>qr) return 0;
        if(ql<=l && qr>=r){
            return t[idx];
        }
        int mid = (l+r)/2;
        return query(2*idx, l, mid, ql, qr) ^ query(2*idx+1, mid+1, r, ql, qr);
    }
};


class Solution {
public:
    vector<vector<int>> adjl;
    vector<int> t;
    int timer;
    int par[100100][19];
    int dep[100100];
    vector<int> intime, outime;
    string s;

    void dfs(int node, int pp, int dd){
        intime[node] = timer;
        t[timer] = (1LL<<(s[node]-'a'));

        dep[node] = dd;
        par[node][0] = pp;

        for(int i=1; i<=18; i++){
            if(par[node][i-1] == -1){
                par[node][i] = -1;
            }else{
                par[node][i] = par[par[node][i-1]][i-1];
            }
        }
        timer++;
        for(int nei: adjl[node]){
            if(nei != pp){
                dfs(nei, node, dd+1);
            }
        }
        outime[node] = timer;
        t[timer] = (1LL<<(s[node]-'a'));
        timer++;
    }

    int lca(int u, int v){
        if(dep[v]>=dep[u]) swap(u, v);
        int diff = dep[u]-dep[v];
        for(int i=18; i>=0; i--){
            if(diff&(1LL<<i)){
                u = par[u][i];
            }
        }
        if(u == v) return u;
        for(int i=18; i>=0; i--){
            if(par[u][i] != par[v][i]){
                u = par[u][i];
                v = par[v][i];
            }
        }
        if(u == v) return u;
        return par[u][0];
    }

    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        adjl.resize(n, vector<int>());
        this->s = s;
        intime.resize(n, 0);
        outime.resize(n, 0);
        for(auto ed: edges){
            int u = ed[0];
            int v = ed[1];
            adjl[u].push_back(v);
            adjl[v].push_back(u);
        }
        
        timer = 0;
        t.resize(4*n, 0);
        dfs(0, -1, 0);

        Seg sg(timer, t);
        vector<bool> ans;
        for(auto q: queries){
            if(q[0] == 'q'){
                int u = 0;
                int j = 6;
                while(q[j]!=' '){
                    u = u*10+(q[j]-'0');
                    j++;
                }
                j++;
                int v = 0;
                while(j<q.size()){
                    v = v*10 + (q[j]-'0');
                    j++;
                }
                // cout<<u<<" "<<v<<endl;
                int lc = lca(u, v);
                int ltu = sg.query(1, 0, timer-1, intime[lc], intime[u]);
                int ltv = sg.query(1, 0, timer-1, intime[lc], intime[v]);
                int cura = (ltu^ltv)^(1LL<<(s[lc]-'a'));
                if(cura == 0){
                    ans.push_back(1);
                }else{
                    int no1 = __builtin_popcountll(cura);
                    if(no1>1){
                        ans.push_back(0);
                    }else{
                        ans.push_back(1);
                    }
                }
            }else{
                int j = 7;
                int u = 0;
                while(q[j]!=' '){
                    u = (u*10) + (q[j]-'0');
                    j++;
                }
                j++;
                char ch = q[j];
                // cout<<u<<" "<<ch<<endl;
                s[u] = ch;
                sg.update(1, 0, timer-1, intime[u], (1LL<<(ch-'a')) );
                sg.update(1, 0, timer-1, outime[u], (1LL<<(ch-'a')) );
            }
        }

        return ans;

        
    }
};