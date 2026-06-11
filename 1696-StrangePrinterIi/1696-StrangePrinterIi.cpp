// Last updated: 6/11/2026, 11:26:56 AM
class Solution {
public:
    bool isPrintable(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        vector<pair<int, int>> topbot(61, {1e9, -1e9});
        vector<pair<int, int>> leftright(61, {1e9, -1e9});

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int c = arr[i][j];
                topbot[c].first = min(topbot[c].first, i);
                topbot[c].second = max(topbot[c].second, i);
                leftright[c].first = min(leftright[c].first, j);
                leftright[c].second = max(leftright[c].second, j);
            }
        }

        vector<vector<int>> adjl(61, vector<int>());
        vector<int> indeg(61, 0);

        for(int c=1; c<=60; c++){
            auto [r1, r2] = topbot[c];
            auto [c1, c2] = leftright[c];
            if(r1 == 1e9) continue;

            for(int i=r1; i<=r2; i++){
                for(int j=c1; j<=c2; j++){
                    if(arr[i][j] == c) continue;
                    int oc = arr[i][j];
                    adjl[c].push_back(oc);
                    indeg[oc]++;
                }
            }
        }

        //khan algo for cycle detection in dag
        queue<int> q;
        int vis = 0;

        for(int i=1; i<=60; i++){
            if(indeg[i] == 0){
                q.push(i);
                vis++;
            }
        }

        while(!q.empty()){
            auto tn = q.front(); q.pop();
            for(int nei: adjl[tn]){
                indeg[nei]--;
                if(indeg[nei] == 0){
                    q.push(nei);
                    vis++;
                }
            }
        }

        if(vis == 60) return 1;
        return 0;


    }
};