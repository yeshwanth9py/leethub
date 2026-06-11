// Last updated: 6/11/2026, 11:16:25 AM
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int bu) {
        int n = items.size();
        int mf = 0;
        int minp = 1e9;
        unordered_map<int, int> freq;
        for(int i=0; i<n; i++){
            mf = max(mf, items[i][0]);
            minp = min(minp, items[i][1]);
            freq[items[i][0]]++;
        }

        vector<int> bad(mf+1, 0);

        for(int i=1; i<=mf; i++){
            if(freq[i] == 0) continue;
            int cnt = 0;
            for(int j=i; j<=mf; j+=i){
                cnt += freq[j];
            }
            bad[i] = cnt-1;
        }

        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>> > pq;

        for(int i=0; i<n; i++){
            int cf = items[i][0];
            if(bad[cf]>0){
                int cost = items[i][1];
                double unitcost = ((1.0*cost)/2.0);
                if(unitcost<minp) pq.push({unitcost, bad[cf]});
            }
        }

        int ans = 0;

        while(!pq.empty()){
            auto [unitcost, free] = pq.top(); pq.pop();
            int fullcost = (2.0*unitcost);
            if(bu<fullcost) break;
            int x = bu/fullcost;
            x = min(x, free);
            ans += 2*x;
            bu -= (x)*fullcost;
        }

        if(bu>0){
            int x = bu/minp;
            ans += x;
        }

        return ans;
    }
};