// Last updated: 6/11/2026, 11:12:07 AM
class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        long long tc = accumulate(cost.begin(), cost.end(), 0LL);
        long long n = s.size();
        unordered_map<char, long long> ump;
        for(long long i=0; i<n; i++){
            ump[s[i]] += cost[i];
        }

        long long minc = 1e18;
        for(auto el: ump){
            long long curc = el.second;
            long long delc = tc-curc;
            minc = min(minc, delc);
        }

        return minc;
        
    }
};