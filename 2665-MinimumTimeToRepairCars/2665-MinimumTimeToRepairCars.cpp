// Last updated: 6/11/2026, 11:21:24 AM

using ll = long long;
class Solution {
public:
    bool check(ll mid, vector<int>& ranks, int cars){
        ll noc = 0;
        for(int i=0; i<ranks.size(); i++){
            noc += sqrt(mid/ranks[i]);
            if(noc>=cars) return 1;
        }
        return noc>=cars;
    }
   ll mod = 1e15+7;
    long long repairCars(vector<int>& ranks, int cars) {
        ll lo = 1;
        ll hi = *min_element(ranks.begin(), ranks.end()) * (long long)cars * cars;
        ll ans = -1;
        while(lo<=hi){
            ll mid = (lo+hi)/2;
            if(check(mid, ranks, cars)){
                ans = mid;
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }

        return ans;
    }
};