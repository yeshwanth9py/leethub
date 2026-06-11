// Last updated: 6/11/2026, 11:13:28 AM
class Solution {
public:
    string s = "";
    long long n;
    long long dp[19][2][2];
    long long countw(long long ind, long long thi, long long fn){
        if(ind == n){
            if(fn == 0) return 0;
            return 1;
        }

        if(dp[ind][thi][fn]!=-1){
            return dp[ind][thi][fn];
        }

        long long lo = 0;
        long long hi = 9;

        if(fn == 1){
            lo = 1;
        }

        if(thi == 1){
            hi = s[ind]-'0';
        }
        

        long long ways = 0;
        for(long long i=lo; i<=hi; i++){
            long long nthi = 0;
            if(thi == 1 && i == hi){
                nthi = 1;
            }
            long long nfn = 1;
            if(fn == 0 && i == 0){
                nfn = 0;
            }

            ways += countw(ind+1, nthi, nfn);
        }

        return dp[ind][thi][fn] = ways;
    }
    
    long long countDistinct(long long n) {
        while(n){
            long long ld = n%10;
            s.push_back('0'+ld);
            n = n/10;
        }
        reverse(s.begin(), s.end());
        this->n = s.size();
        memset(dp, -1, sizeof(dp));
        return countw(0, 1, 0);
    }
};