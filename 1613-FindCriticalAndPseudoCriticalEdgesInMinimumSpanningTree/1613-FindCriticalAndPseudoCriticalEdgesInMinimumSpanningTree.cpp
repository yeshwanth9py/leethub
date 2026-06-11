// Last updated: 6/11/2026, 11:27:21 AM
int par[111][21];
pair<int, vector<int>> dp[111][21];
int dep[111];

vector<vector<pair<int, int>>> adjl;
map<pair<int, int>, int> ump;

void dfs(int node, int pp, int dd, int pwt){
    par[node][0] = pp;
    dep[node] = dd;
    int edgno = ump[{min(node, pp), max(node, pp)}];
    
    if(pp != -1){
        dp[node][0] = {pwt, {edgno}};
    }else{
        dp[node][0] = {pwt, {}};
    }

    for(int i=1; i<21; i++){
        if(par[node][i-1] != -1){
            par[node][i] = par[par[node][i-1]][i-1];
        
            if(dp[par[node][i-1]][i-1].first>dp[node][i-1].first){
                dp[node][i] = dp[par[node][i-1]][i-1];
            }else if(dp[par[node][i-1]][i-1].first == dp[node][i-1].first){
                dp[node][i] = dp[node][i-1];
                for(int el: dp[par[node][i-1]][i-1].second){
                    dp[node][i].second.push_back(el);
                }
            }else{
                dp[node][i] = dp[node][i-1];
            }
        }else{
            par[node][i] = -1;
            dp[node][i] = dp[node][i-1];
        }
    }
    
    // cout<<node<<" - "<<pp<<endl;

    for(auto [nei, neiwt]: adjl[node]){
        if(nei != pp){
            dfs(nei, node, dd+1, neiwt);
        }
    }
    
}


auto findmaxwt(int a, int b){
    if(dep[a]>=dep[b]) swap(a, b);
    int diff = dep[b]-dep[a];

    pair<int, vector<int>> mxwt;

    for(int i=20; i>=0; i--){
        if((diff&(1LL<<i)) != 0){
            if(dp[b][i].first>mxwt.first){
                mxwt = dp[b][i];
            }else if(dp[b][i].first == mxwt.first){
                for(int el: dp[b][i].second){
                    mxwt.second.push_back(el);
                }
            }
            b = par[b][i];
        }
    }

    if(a == b) return mxwt;

    for(int i=20; i>=0; i--){
        if(par[a][i] != par[b][i]){
            if(dp[b][i].first>mxwt.first){
                mxwt = dp[b][i];
            }else if(dp[b][i].first == mxwt.first){
                for(int el: dp[b][i].second){
                    mxwt.second.push_back(el);
                }
            }

            if(dp[a][i].first>mxwt.first){
                mxwt = dp[a][i];
            }else if(dp[a][i].first == mxwt.first){
                for(int el: dp[a][i].second){
                    mxwt.second.push_back(el);
                }
            }

            // mxwt = max({mxwt, dp[a][i], dp[b][i]});
            a = par[a][i];
            b = par[b][i];
        }
    }


    // mxwt = max({mxwt, dp[a][0], dp[b][0]});

    if(dp[b][0].first>mxwt.first){
        mxwt = dp[b][0];
    }else if(dp[b][0].first == mxwt.first){
        for(int el: dp[b][0].second){
            mxwt.second.push_back(el);
        }
    }

    if(dp[a][0].first>mxwt.first){
        mxwt = dp[a][0];
    }else if(dp[a][0].first == mxwt.first){
        for(int el: dp[a][0].second){
            mxwt.second.push_back(el);
        }
    }
    
    if(dp[b][0].first>mxwt.first){
        mxwt = dp[b][0];
    }else if(dp[b][0].first == mxwt.first){
        
    }

    return mxwt;
}

struct Unionfind{
    vector<int> sz;
    vector<int> par;
    Unionfind(int n){
        par.resize(n, 0);
        sz.resize(n, 1);
        for(int i=0; i<n; i++) par[i] = i;
    }

    int find(int x){
        if(par[x] == x) return x;
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
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        Unionfind uf(n);
        memset(par, -1, sizeof(par));
        // memset(dp, 0, sizeof(dp));
        memset(dep, 0, sizeof(dep));
        ump.clear();

        for(int i=0; i<=101; i++){
            for(int j=0; j<21; j++){
                dp[i][j] = {0, {}};
            }
        }

        for(int i=0; i<edges.size(); i++){
            edges[i].push_back(i);
            int u = edges[i][0];
            int v = edges[i][1];
            ump[{min(u, v), max(u, v)}] = i;
        }

        sort(edges.begin(), edges.end(), [&](vector<int> &a, vector<int> &b){
            return a[2]<b[2];
        });

        adjl.assign(n, vector<pair<int, int>>());

        vector<vector<int>> oedges;

        set<int> crit;
        set<int> pseudo;

        unordered_map<int, vector<int>> ump;

        for(auto edg: edges){
            int a = edg[0];
            int b = edg[1];
            int wt = edg[2];

            if(uf.find(a) == uf.find(b)) {
                oedges.push_back({a, b, wt, edg[3]});
                continue;
            }

            uf.merge(a, b);
            adjl[a].push_back({b, wt});
            adjl[b].push_back({a, wt});

            crit.insert(edg[3]);
            ump[wt].push_back(edg[3]);
        }

        dfs(0, -1, 0, 0);

        for(auto edg: oedges){
            int a = edg[0];
            int b = edg[1];

            int wt = edg[2];

            auto [maxwtbtw, edgnos] = findmaxwt(a, b);

            if(maxwtbtw == wt){
                for(int el: edgnos){
                    if(crit.find(el) != crit.end()){
                        crit.erase(el);
                        pseudo.insert(el);
                    }
                }
                pseudo.insert(edg[3]);
            }
        }

        
        vector<vector<int>> ans;
        vector<int> temp1, temp2;

        for(int el: crit){
            temp1.push_back(el);
        }

        for(int el: pseudo){
            temp2.push_back(el);
        }

        ans.push_back(temp1);
        ans.push_back(temp2);

        return ans;

    }
};