// Last updated: 6/11/2026, 11:28:14 AM
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<vector<int>> revadjl(n, vector<int>());

        queue<int> q;
        vector<int> dist(n, 1e9);

        for(int i=0; i<n; i++){
            int nxt = i+arr[i];
            if(nxt<n){
                revadjl[nxt].push_back(i);
            }
            nxt = i-arr[i];
            if(nxt>=0){
                revadjl[nxt].push_back(i);
            }
            if(arr[i] == 0){
                q.push(i);
                dist[i] = 0;
            }
        }


        while(!q.empty()){
            auto tn = q.front(); q.pop();
            for(int nei: revadjl[tn]){
                if(dist[nei]>dist[tn]+1){
                    dist[nei] = dist[tn]+1;
                    q.push(nei);
                }
            }
        }

        if(dist[start] >= 1e8) return 0;
        return 1;
    }
};