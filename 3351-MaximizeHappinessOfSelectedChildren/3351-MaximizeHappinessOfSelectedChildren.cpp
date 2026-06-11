// Last updated: 6/11/2026, 11:18:40 AM
class Solution {
public:
    long long maximumHappinessSum(vector<int>& arr, int k) {
        long long tk = 0;
        priority_queue<long long> pq;
        for(long long el: arr) pq.push(el);

        long long tsum = 0;
        while(!pq.empty()){
            long long tel = pq.top(); pq.pop();
            tsum += max(0LL, (tel-tk));
            tk++;
            if(tk == k) break;
        }
        return tsum;
    }
};