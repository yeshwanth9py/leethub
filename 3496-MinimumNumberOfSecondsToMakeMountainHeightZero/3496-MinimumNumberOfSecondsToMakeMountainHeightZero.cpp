// Last updated: 6/11/2026, 11:17:53 AM
class Solution {
public:
    long long minNumberOfSeconds(int mht, vector<int>& wt) {
        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> pq;  //time, i, mul
        for(long long i=0; i<wt.size(); i++){
            pq.push({wt[i], i, 1});
        }

        long long curt = 0;

        for(long long i=1; i<=mht; i++){
            auto tel = pq.top(); pq.pop();
            long long ct = tel[0];
            long long ind = tel[1];
            long long k = tel[2];
            
            curt = max(ct, curt);

            pq.push({ct + wt[ind]*(k+1), ind, k+1});
        }

        return curt;
        
    }
};



