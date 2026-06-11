// Last updated: 6/11/2026, 11:27:52 AM
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int mx = 1e5;
        vector<int> all(mx+1, 0);
        unordered_map<int, vector<int>> ump;
        for(auto el: events){
            ump[el[1]].push_back(el[0]);
        }
        priority_queue<int> pq;
        int cnt = 0;
        for(int i=mx; i>=1; i--){
            for(int st: ump[i]){
                pq.push(st);
            }
            while(!pq.empty() && pq.top()>i){
                pq.pop();
            }
            if(!pq.empty()){
                cnt++;
                pq.pop();
            }
        }

        return cnt;
    }
};