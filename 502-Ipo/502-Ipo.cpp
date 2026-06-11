// Last updated: 6/11/2026, 11:32:53 AM
// struct Comp{

// };

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& pr, vector<int>& ca) {
        priority_queue<pair<long long, long long>> pq;
        long long n = pr.size();
        

        vector<pair<long long, long long>> vec;
        for(long long i=0; i<n; i++){
            vec.push_back({ca[i], pr[i]});
        }

        sort(vec.begin(), vec.end());

        long long i = 0;
        long long taken = 0;
        long long tot = w;

        if(taken == k) return tot;

        while(i<n){
            while(i<n && vec[i].first<=tot){
                pq.push({vec[i].second, vec[i].first});
                i++;
            }
            if(pq.size() == 0) break;
            auto [curpr, curca] = pq.top(); pq.pop();
            taken++;
            tot += curpr;
            if(taken>=k) return tot;
        }

        while(!pq.empty() && taken<k){
            auto [curpr, curca] = pq.top(); pq.pop();
            taken++;
            tot += curpr;
        }
        
        return tot;
    }

};