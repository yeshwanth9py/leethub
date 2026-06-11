// Last updated: 6/11/2026, 11:19:09 AM
using ll = long long;
ll dp[17][2][2];
class Solution {
public:
    string lo;
    string hi;
    int pre_len;
    int limit;
    string s;
    ll rec(int ind, int tlo, int thi){
        if(ind == hi.length()){
            return 1;
        }
        if(dp[ind][tlo][thi]!=-1){
            return dp[ind][tlo][thi];
        }
        int l = 0;
        int h = 9;
        if(tlo == 1){
            l = lo[ind]-'0';
        }
        if(thi == 1){
            h = hi[ind]-'0';
        }
        ll ways = 0;
        if(ind<pre_len){
            for(int i=l; i<=min(limit, h); i++){
                int ntlo = tlo;
                int nthi = thi;
                if(i != l) ntlo = 0;
                if(i!=h) nthi = 0;
                ways += rec(ind+1, ntlo, nthi);
            }
        }else{
            int x = s[ind-pre_len]-'0';
            if(x>=l && x<=min(h, limit)){
                int ntlo = tlo;
                int nthi = thi;
                if(x!=l) ntlo = 0;
                if(x!=h) nthi = 0;
                ways += rec(ind+1, ntlo, nthi);
            }
        }
        return dp[ind][tlo][thi] = ways;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        lo = to_string(start);
        hi = to_string(finish);
        this->limit = limit;
        this->s = s;
        pre_len = hi.length()-lo.length();
        if(pre_len>0){
            string temp = "";
            while(pre_len--){
                temp += "0";
            }
            lo = temp + lo;
        }
        pre_len = hi.length()-s.length();
        if(pre_len<0){
            return 0;
        }
        memset(dp, -1, sizeof(dp));
        return rec(0, 1, 1);
    }
};