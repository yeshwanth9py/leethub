// Last updated: 6/11/2026, 11:15:59 AM
class Solution {
public:
    long long n;
    vector<long long> doubled;
    long long s;
    long long get1dist(long long x, long long y){
        if(y == 0) return x;
        if(x == s) return s+y;
        if(y == s) return 3*s - x;
        return 4*s - y;
    }

    bool check(long long mid, long long k, vector<long long> &doubled){
        long long perim = 4*s;
        for(long long i=0; i<n; i++){
            long long st = doubled[i];
            long long cnt = 1;
            long long prev = st;
            for(long long j=1; j<k; j++){
                auto it = lower_bound(doubled.begin()+i+1, doubled.begin()+i+n+1, prev+mid);
                if(it == doubled.begin()+i+n+1) break;
                cnt++;
                prev = *it;
            }

            if(cnt >= k && (st+perim-prev>=mid)){
                return 1;
            }
        }
        return 0;
    }

    int maxDistance(int s, vector<vector<int>>& points, int k) {
        n = points.size();
        this->s = 1LL*s;
        doubled.resize(2*n, 0LL);

        for(long long i=0; i<n; i++){
            long long dis = get1dist(points[i][0], points[i][1]);
            doubled[i] = dis;
            doubled[i+n] = 1LL*4*s + dis;
        }

        sort(doubled.begin(), doubled.end());
        
        long long lo = 0;
        long long hi = 2*s;
        long long ans = 0;

        while(lo<=hi){
            long long mid = (lo+hi)/2;
            if(check(mid, k, doubled)){
                ans = mid;
                lo = mid+1;
            }else{
                hi = mid-1;
            }
        }

        return ans;
    }
};


