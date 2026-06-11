// Last updated: 6/11/2026, 11:33:43 AM
struct Seg{
    vector<long long> t;
    Seg(long long m){
        t.resize(4*m, 0);
    }

    void update(long long idx, long long l, long long r, long long pos){
        if(pos < l || pos > r) return;
        if(l == r){
            t[idx] += 1;
            return;
        }
        long long mid = (l + r) / 2;
        update(2*idx, l, mid, pos);
        update(2*idx+1, mid+1, r, pos);
        t[idx] = t[2*idx] + t[2*idx+1];
    }

    long long query(long long idx, long long l, long long r, long long ql, long long qr){
        if(qr < l || r < ql) return 0;
        if(ql <= l && r <= qr) return t[idx];
        long long mid = (l + r) / 2;
        return query(2*idx, l, mid, ql, qr) + query(2*idx+1, mid+1, r, ql, qr);
    }
};

class Solution {
public:
    long long m;
    long long countRangeSum(vector<int>& nums, int lower, int upper) {
        long long n = nums.size();
        if(n == 0) return 0;

       
        vector<long long> pref(n, 0);
        for(long long i = 0; i < n; ++i){
            pref[i] = ((i-1 >= 0) ? pref[i-1] : 0) + nums[i];
        }

        
        map<long long, long long> ump;
        for(long long i = 0; i < n; ++i){
            long long s = pref[i];
            ump[s] = 1;
            ump[s - (long long)lower] = 1;
            ump[s - (long long)upper] = 1;
        }
       
        ump[0] = 1;
        ump[0 - (long long)lower] = 1;
        ump[0 - (long long)upper] = 1;

        
        long long idx = 0;
        for(auto &el : ump){
            el.second = idx++;
        }
        m = idx;
        Seg sg(m);

        
        sg.update(1, 0, m-1, ump[0]); 

        long long cnt = 0;

        
        for(long long j = 0; j < n; ++j){
            long long x = pref[j];
            long long a = ump[x - (long long)upper]; 
            long long b = ump[x - (long long)lower]; 

            long long l = min(a, b);
            long long r = max(a, b);

            
            if(l <= r) cnt += sg.query(1, 0, m-1, l, r);

            sg.update(1, 0, m-1, ump[x]);
        }

        return cnt;
    }
};
