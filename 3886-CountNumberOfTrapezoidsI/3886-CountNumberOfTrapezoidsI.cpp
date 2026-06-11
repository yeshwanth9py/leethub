// Last updated: 6/11/2026, 11:14:53 AM

class Solution {
public:
    const long long mod = 1e9+7;
    int countTrapezoids(vector<vector<int>>& ps) {
        unordered_map<long long, long long> ump;
        for(auto vec: ps){
            long long a = vec[0];
            long long b = vec[1];
            ump[b]++;
        }

        vector<long long> temp;
        long long ts = 0;
        for(auto el: ump){
            long long v = el.second;
            v = (v*(v-1))/2;
            v = (v%mod + mod)%mod;
            temp.push_back(v);
            ts = (ts+v)%mod;
            ts = (ts+mod)%mod;
        }

        long long ans = 0;
        for(long long el: temp){
            ts = ((ts-el)%mod + mod)%mod;
            ans += ((ts*el)%mod+mod)%mod;
            ans = (ans+mod)%mod;
        }

        return ans;

    }
};