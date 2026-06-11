// Last updated: 6/11/2026, 11:12:23 AM
struct Seg{
    vector<long long> t;
    Seg(long long n){
        t.resize(4*n, -1e18);
    }
    void build(long long ind, long long l, long long r, vector<long long> &temp){
        if(l == r){
            t[ind] = temp[l];
            return;
        }
        long long mid = (l+r)/2;
        build(2*ind, l, mid, temp);
        build(2*ind+1, mid+1, r, temp);
        t[ind] = max(t[2*ind], t[2*ind+1]);
    }
    long long query(long long ind, long long l, long long r, long long ql, long long qr){
        if(r<ql || qr<l) return -1e18;
        if(ql<=l && qr>=r){
            return t[ind];
        }
        long long mid = (l+r)/2;
        return max(query(2*ind, l, mid, ql, qr), query(2*ind+1, mid+1, r, ql, qr));
    }
};

class Solution {
public:
    long long n;
    vector<long long> summ;
    long long l;
    long long r;
    long long m;
    long long dp[1010][1010];
    long long rec(){
        Seg sg(n+2);
        for(long long no=m+1; no>=0; no--){
            vector<long long> temp(n+2, -1e18);
            for(long long ind=n; ind>=0; ind--){
                if(no>m){
                    dp[ind][no] = -1e18;
                    continue;
                }
                if(ind == n){
                    if(no>=1 && no<=m){
                        dp[ind][no] = 0;
                    }else{
                        dp[ind][no] = -1e18;
                    }
                    continue;
                }

                long long ans = dp[ind+1][no];

                // for(long long nind=ind+l-1; nind<=min(n-1, r+ind-1); nind++){
                //     long long cur = summ[nind] - (ind-1>=0?summ[ind-1]:0) + dp[nind+1][no+1];
                //     ans = max(ans, cur);
                // }

                long long cur = sg.query(1, 0, n+1, ind+l-1, min(n-1, r+ind-1)) - (ind-1>=0?summ[ind-1]:0);
                ans = max(ans, cur);
                dp[ind][no] = ans;
                temp[ind] = max(temp[ind], dp[ind+1][no] + summ[ind]);
            }

            sg.build(1, 0, n+1, temp);
        }

        return dp[0][0];
    }

    
    long long maximumSum(vector<int>& nums, long long mm, long long ll, long long rr) {
        n = nums.size();
        l = ll;
        r = rr;
        m = mm;
        summ.assign(n, 0);
        summ[0] = nums[0];
        for(long long i=1; i<n; i++){
            summ[i] = summ[i-1] + nums[i];
        }

        return rec();
    }
};