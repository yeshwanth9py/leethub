// Last updated: 6/11/2026, 11:30:44 AM
struct Seg{
    vector<long long> t;
    Seg(long long m){
        t.resize(4*m, -1e9);
    }
    
    long long query(long long idx, long long l, long long r, long long ql, long long qr){
        if(r<ql || qr<l) return -1e9;
        if(l>=ql && r<=qr){
            return t[idx];
        }
        long long mid = (l+r)/2;
        return max(query(2*idx, l, mid, ql, qr), query(2*idx+1, mid+1, r, ql, qr));
    }

    void update(long long idx, long long l, long long r, long long pos, long long val){
        if(pos<l || pos>r) return;
        if(l == r){
            t[idx] = val;
            return;
        }
        long long mid = (l+r)/2;
        update(2*idx, l, mid, pos, val);
        update(2*idx+1, mid+1, r, pos, val);
        t[idx] = max(t[2*idx], t[2*idx+1]);
    }

};


class Solution {
public:
    long long m;
    long long shortestSubarray(vector<int>& nums, int k) {
        long long n = nums.size();
        vector<long long> pref(n+1, 0);
        for(long long i=1; i<=n; i++){
            pref[i] = pref[i-1]+nums[i-1];
        }

        map<long long, long long> ump;
        for(long long i=0; i<=n; i++){
            ump[pref[i]-k] = 1;
            ump[pref[i]] = 1;
        }

        long long id = 0;
        for(auto el: ump){
            ump[el.first] = id;
            id++;
        }
        m = id;

        Seg sg(m);
        sg.update(1, 0, m-1, ump[0], 0);

        long long ans = 1e9;
        for(long long i=1; i<=n; i++){
            long long val = ump[pref[i]-k];
            long long pidx = sg.query(1, 0, m-1, 0, val);
            if(pidx>=0) ans = min(ans, i-pidx);
            sg.update(1, 0, m-1, ump[pref[i]], i);
        }

        if(ans>=1e9) return -1;
        return ans;

    }
};