// Last updated: 6/11/2026, 11:11:55 AM
class Solution {
public:
    long long check(long long md, long long c1, long long c2, long long cb, long long n1, long long n2){
        long long tc = max(0LL, (n1-md))*c1 + max(0LL, (n2-md))*c2 + cb*md;
        return tc;
    }

    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long mans = 1LL*need1*cost1 + 1LL*need2*cost2;
        long long tc = mans;
        
        long long lo = 1;
        long long hi = 1e9;
        long long ans = mans;

        while(lo<=hi){
            long long mid = (lo+hi)/2;
            if(check(mid-1, cost1, cost2, costBoth, need1, need2)>check(mid, cost1, cost2, costBoth, need1, need2)){
                ans = check(mid, cost1, cost2, costBoth, need1, need2);
                lo = mid+1;
            }else{
                hi = mid-1;
            }
        }

        return min(mans, ans);


    }
};