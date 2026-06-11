// Last updated: 6/11/2026, 11:21:37 AM
class Solution {
public:
    bool check(long long md, vector<long long> arr, long long r, long long k){
        long long n = arr.size();
        vector<long long> part(n, 0);
        long long rems = k;
        for(long long i=0; i<n; i++){
            part[i] += (i-1>=0?part[i-1]:0);
            long long curv = arr[i]+part[i];

            if(curv<md){
                long long ex = md-curv;
                if(ex>rems) return 0;
                rems -= ex;
                part[i] += ex;
                if(i+2*r+1<n){
                    part[i+2*r+1] -= ex;
                }
            }
        }

        return 1;
    }
    
    long long maxPower(vector<int>& sta, int r, int k) {
        long long n = sta.size();
        vector<long long> psum(n, 0);
        psum[0] = sta[0];
        for(long long i=1; i<n; i++){
            psum[i] = psum[i-1]+sta[i];
        }

        vector<long long> arr(n, 0);
        for(long long i=0; i<n; i++){
            long long currs = ((i+r<n)?(psum[i+r]):psum[n-1]);
            long long curls = (i-r-1>=0?(psum[i-r-1]):0);
            arr[i] = currs - curls;
        }

        long long lo = *(min_element(arr.begin(), arr.end()));
        long long hi = 1e18;

        long long ans = lo;

        while(lo<=hi){
            long long mid = (lo+hi)/2;
            if(check(mid, arr, r, k)){
                ans = mid;
                lo = mid+1;
            }else{
                hi = mid-1;
            }
        }

        return 1LL*ans;

        
    }
};