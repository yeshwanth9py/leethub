// Last updated: 6/11/2026, 11:22:40 AM
class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n, 1e9);
        priority_queue<pair<int, int>> q;
        q.push({0, node1});
        dist1[node1] = 0;

        while(!q.empty()){
            auto tel = q.top(); q.pop();
            int cn = tel.second;
            int j = edges[cn];
            if(j == -1) continue;
            if(dist1[j]>dist1[cn]+1){
                dist1[j] = dist1[cn]+1;
                q.push({-dist1[j], j});
            }
        }

        vector<int> dist2(n, 1e9);
        dist2[node2] = 0;

        q.push({0, node2});
        
        while(!q.empty()){
            auto tel = q.top(); q.pop();
            int cn = tel.second;
            int j = edges[cn];
            if(j == -1) continue;
            if(dist2[j]>dist2[cn]+1){
                dist2[j] = dist2[cn]+1;
                q.push({-dist2[j], j});
            }
        }
        
        int ansnode = -1;
        int mindist = 1e9;

        for(int i=0; i<n; i++){
            // if(dist1[i]!=1e9 && dist2[i]!=1e9){
                int maxd = max(dist1[i], dist2[i]);
                if(mindist>maxd){
                    mindist = maxd;
                    ansnode = i;
                }
            // }
        }

        return ansnode;
    }
};