// Last updated: 6/11/2026, 11:21:54 AM
class Solution {
public:
    // vector<vector<int>> edges;
    vector<int> amount;
    unordered_map<int, vector<int>> adjl;
    int ans = -1e9;
    void bfs(int node, int par, int ctime, int camt, unordered_map<int, int> &alltimes){
        bool has_child = 0;
        for(int nei: adjl[node]){
            if(nei == par) continue;
            has_child = 1;
            if(alltimes.find(nei)!=alltimes.end()){
                if(alltimes[nei]<ctime+1){
                    bfs(nei, node, ctime+1, camt+0, alltimes);
                }else if(alltimes[nei] == ctime+1){
                    bfs(nei, node, ctime+1, camt+(amount[nei]/2), alltimes);
                }else{
                    bfs(nei, node, ctime+1, camt+amount[nei], alltimes);
                }
            }else{
                bfs(nei, node, ctime+1, camt+amount[nei], alltimes);
            }
        }

        if(!has_child){
            ans = max(ans, camt);
        }
    }

    bool dfs(int node, int par, unordered_map<int, int> &times, int ctime){
        if(node == 0){
            times[0] = ctime;
            return true;
        }
        for(auto nei: adjl[node]){
            if(par == nei) continue;
            if(dfs(nei, node, times, ctime+1)){
                times[node] = ctime;
                return true;
            }
        }
        return false;

    }
    

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        adjl.clear();
        this->amount= amount;
        for(auto vec: edges){
            adjl[vec[0]].push_back(vec[1]);
            adjl[vec[1]].push_back(vec[0]);
        }

        unordered_map<int, int> times;
        ans = -1e9;

        dfs(bob, -1, times, 0);
        
        bfs(0, -1, 0, amount[0], times);

        
        return ans;

    }
};