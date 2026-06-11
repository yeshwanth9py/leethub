// Last updated: 6/11/2026, 11:31:56 AM
class Solution {
public:
    int findparent(int cn, vector<int> &ds){
        if(cn == ds[cn]){
            return cn;
        }
        return ds[cn] = findparent(ds[cn], ds);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // union find disjoint set algorithm
        int n = edges.size();
        vector<int> ds(n+1, 0);
        vector<int> rank(n+1, 1);

        for(int i=0; i<=n; i++){
            ds[i] = i;
        }

        for(vector<int> ed: edges){
            int p1 = findparent(ed[0], ds);
            int p2 = findparent(ed[1], ds);
            if(p1 == p2){
                return ed;
            }
            // else{
                if(rank[p1]<rank[p2]){
                    ds[p1] = p2;
                }else if(rank[p2]<rank[p1]){
                    ds[p2] = p1;
                }else{
                    ds[p1] = p2;
                    rank[p2]++;
                }
            // }
        }
        return {};

    }
};