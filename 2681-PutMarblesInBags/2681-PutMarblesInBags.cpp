// Last updated: 6/11/2026, 11:21:21 AM

using ll = long long;
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        priority_queue<pair<ll, pair<ll, ll>>> pq;
        ll n = weights.size();
        for(ll i=0; i<n-1; i++){
            pq.push({weights[i]+weights[i+1], {i, i+1}});
        }

        ll cnt = k;
        cnt--;
        ll maxsum = 0;
        ll prev1 = -1;
        ll prev2 = -1;
        while(cnt && !pq.empty()){
            auto tel = pq.top();
            pq.pop();
            if(tel.second.first == prev1 || tel.second.second == prev2){
                continue;
            }

            prev1 = tel.second.first;
            prev2 = tel.second.second;

            maxsum += tel.first;
            cnt--;
        }

        while(!pq.empty()){
            pq.pop();
        }
        // int n = weights.size();
        for(int i=0; i<n-1; i++){
            pq.push({-(weights[i]+weights[i+1]), {i, i+1}});
        }

        cnt = k;
        cnt--;
        ll minsum = 0;
        prev1 = -1;
        prev2 = -1;
        while(cnt && !pq.empty()){
            auto tel = pq.top();
            pq.pop();
            if(tel.second.first == prev1 || tel.second.second == prev2){
                continue;
            }

            prev1 = tel.second.first;
            prev2 = tel.second.second;

            minsum += -tel.first;
            cnt--;
        }

        return maxsum-minsum;

    }
};