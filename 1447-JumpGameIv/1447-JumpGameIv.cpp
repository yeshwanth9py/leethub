// Last updated: 6/11/2026, 11:28:10 AM
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> ump;
        for(int i=0; i<arr.size(); i++){
            ump[arr[i]].push_back(i);
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        pq.push({0, 0});

        vector<int> dist(n, 1e9);
        dist[0] = 0;
        while(!pq.empty()){
            auto [td, tn] = pq.top(); pq.pop();
            if(dist[tn] != td) continue;
            if(tn-1>=0 && dist[tn-1]>dist[tn]+1){
                dist[tn-1] = dist[tn]+1;
                pq.push({dist[tn-1], tn-1});
            }
            if(tn+1<n && dist[tn+1]>dist[tn]+1){
                dist[tn+1] = dist[tn]+1;
                pq.push({dist[tn+1], tn+1});
            }
            for(int nei: ump[arr[tn]]){
                if(dist[nei]>dist[tn]+1){
                    dist[nei] = dist[tn]+1;
                    pq.push({dist[nei], nei});
                }
            }
            ump.erase(arr[tn]);
        }

        return dist[n-1];

    }
};