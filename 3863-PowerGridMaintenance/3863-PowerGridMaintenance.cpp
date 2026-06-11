// Last updated: 6/11/2026, 11:15:06 AM
class Solution {
public:
    vector<vector<int>> adjl;
    vector<int> number;
    vector<int> vis;

    void dfs(int node, int no){
        number[node] = no;
        vis[node] = 1;
        for(int nei: adjl[node]){
            if(vis[nei] == 0){
                dfs(nei, no);
            }
        }
    }

    vector<int> processQueries(int c, vector<vector<int>>& con, vector<vector<int>>& quer) {
        adjl.clear();
        adjl.resize(c, vector<int>());
        for(auto el: con){
            int u = el[0];
            int v = el[1];
            u--;
            v--;
            adjl[u].push_back(v);
            adjl[v].push_back(u);
        }

        vis.resize(c, 0);
        number.resize(c, -1);

        int no = 0;
        for(int i=0; i<c; i++){
            if(vis[i] == 0){
                no++;
                dfs(i, no);
            }
        }

        for(int i=0; i<c; i++){
            cout<<number[i]<<" ";
        }
        cout<<endl;

        unordered_map<int, multiset<int>> ump;
        for(int i=0; i<c; i++){
            ump[number[i]].insert(i);
        }

        vector<int> ans;

        for(auto q: quer){
            int sq = q[0];
            int x = q[1];
            x--;
            if(sq == 1){
                if(ump[number[x]].find(x)!=ump[number[x]].end()){
                    ans.push_back(x+1);
                }else{
                    if(ump[number[x]].size() == 0){
                        ans.push_back(-1);
                    }else{
                        int fv = *(ump[number[x]].begin());
                        ans.push_back(fv+1);
                    }
                }
            }else{
                ump[number[x]].erase(x);
            }
        }

        return ans;

    }
};