// Last updated: 6/11/2026, 11:23:37 AM
class Solution {
public:
    bool check(long long md, vector<int> &arr, long long n){
        long long ts = 0;
        for(long long i=0; i<arr.size(); i++){
            ts += min(1LL*arr[i], md);
        }
        return ts>=(n*md);
    }

    long long maxRunTime(int n, vector<int>& arr) {
        long long sum = accumulate(arr.begin(), arr.end(), 0LL);
        long long lo = *(min_element(arr.begin(), arr.end()));
        long long hi = sum/n;
        long long ans = 0;
        while(lo<=hi){
            long long mid = (lo+hi)/2;
            if(check(mid, arr, n)){
                ans = mid;
                lo = mid+1;
            }else{
                hi = mid-1;
            }
        }
        return ans;
    }
};