// Last updated: 6/11/2026, 11:19:13 AM
class Solution {
public:
    long long get_i_ones(long long num, long long i){
        long long o = (num+1LL)/(1LL<<(i+1LL));
        o = o*(1LL<<i);
        long long ex = max(0LL, ((num+1LL)%(1LL<<(i+1))) - (1LL<<i));
        return o+ex;
    }

    long long sum_of_ones_from_1tonum(long long num, long long x){
        long long sum = 0;
        for(long long i=x; i<60; i=i+x){
            sum += get_i_ones(num, i-1);
        }
        return sum;
    }

    long long findMaximumNumber(long long k, long long x) {
        long long lo = 0;
        long long hi = 1e15;
        long long ans = 0;
        while(lo<=hi){
            long long mid = (lo+hi)/2;
            if(sum_of_ones_from_1tonum(mid, x)<=k){
                ans = mid;
                lo = mid+1;
            }else{
                hi = mid-1;
            }
        }

        return ans;
    }
};