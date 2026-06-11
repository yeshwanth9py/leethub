// Last updated: 6/11/2026, 11:21:19 AM
class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<long long, long long> ump;
        long long minel = basket1[0];
        for(long long el: basket1){
            minel = min(minel, el);
            ump[el]++;
        }
        for(long long el: basket2){
            minel = min(minel, el);
            ump[el]--;
        }

        vector<long long> balance;
        for(auto el: ump){
            if(abs(el.second)%2 != 0) return -1;
            long long cnt = abs(el.second/2);
            for(long long i=0; i<cnt; i++){
                balance.push_back(el.first);
            }
        }

        sort(balance.begin(), balance.end());


        long long cost = 0;
        for(int i=0; i<balance.size()/2; i++){
            int curc = min(balance[i], 2*minel);
            cost += curc;
        }

        return cost;
    }
};