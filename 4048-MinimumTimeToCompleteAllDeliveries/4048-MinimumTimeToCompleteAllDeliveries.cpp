// Last updated: 6/11/2026, 11:13:31 AM
class Solution {
public:
    bool check(long long mid, vector<int> &d, vector<int> &r){
        long long tot = mid - mid/lcm(r[0], r[1]);
        if(tot<(d[0]+d[1])) return 0;

        long long t1 = mid-(mid/r[0]);
        if(t1<d[0]) return 0;

        long long t2 = mid - (mid/r[1]);
        if(t2<d[1]) return 0;

        return 1;
    }

    long long minimumTime(vector<int>& d, vector<int>& r) {
        long long lo = 1;
        long long hi = 1e18;
        long long ans = -1;

        while(lo<=hi){
            long long mid = (lo+hi)/2;
            if(check(mid, d, r)){
                ans = mid;
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }

        return ans;

    }
};