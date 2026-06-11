// Last updated: 6/11/2026, 11:28:53 AM

class Solution {
public:
    vector<int> grp_indeg;
    vector<int> indeg;
    vector<vector<int>> adjl_grp;
    vector<vector<int>> nodes;

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& befit) {
        indeg.resize(n, 0);

        int ex = m;
        for(int i=0; i<n; i++){
            if(group[i] == -1){
                group[i] = ex;
                ex++;
            }
        }

        grp_indeg.resize(ex, 0);
        adjl_grp.resize(ex, vector<int>());
        nodes.resize(n, vector<int>());


        for(int i=0; i<befit.size(); i++){
            int cur = i;
            for(int el: befit[i]){
                if(group[el] != group[i]){
                    adjl_grp[group[el]].push_back(group[i]);
                    grp_indeg[group[i]]++;
                }
                nodes[el].push_back(cur);
                indeg[cur]++;
            }
        }

        vector<int> ansg;

        queue<int> q;
        for(int i=0; i<ex; i++){
            if(grp_indeg[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            auto tn = q.front(); q.pop();
            ansg.push_back(tn);

            for(int nei: adjl_grp[tn]){
                grp_indeg[nei]--;
                if(grp_indeg[nei] == 0){
                    q.push(nei);
                }
            }
        }

        if(ansg.size() != ex) return {};

        unordered_map<int, int> ump;
        for(int i=0; i<ansg.size(); i++){
            ump[ansg[i]] = i;
        }

        vector<int> asans;

        auto cmp = [&](int a, int b){
            return ump[group[a]] > ump[group[b]];
        };

        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

        for(int i=0; i<n; i++){
            if(indeg[i] == 0){
                pq.push(i);
            }
        }

        while(!pq.empty()){
            auto tn = pq.top(); pq.pop();
            asans.push_back(tn);
            for(int nei: nodes[tn]){
                indeg[nei]--;
                if(indeg[nei] == 0){
                    pq.push(nei);
                }
            }
        }

        if(asans.size() != n) return {};


        return asans;
    }
};