// Last updated: 6/11/2026, 11:20:31 AM
class Solution {
public:
    string lo;
    string hi;
    int dp[6][2][2][46][46][6];
    int rec(int ind, int tlo, int thi, int leftsum, int rightsum, int st, int ln){
        if(ind == hi.length()){
            if(ln%2 == 0 && leftsum == rightsum){
                return 1;
            }
            return 0;
        }
        if(dp[ind][tlo][thi][leftsum][rightsum][ln]!=-1){
            return dp[ind][tlo][thi][leftsum][rightsum][ln];
        }

        int l = 0;
        int h = 9;
        if(tlo == 1){
            l = lo[ind]-'0';
        }
        if(thi == 1){
            h = hi[ind]-'0';
        }
        int ways = 0;
        bool fh = 1;
        if(hi.length()-ind>ln){
            fh = 1;
        }else{
            fh = 0;
        }
        for(int i=l; i<=h; i++){
            int ntlo = tlo;
            int nthi = thi;
            if(i != l) ntlo = 0;
            if(i!=h) nthi = 0;
            if(fh == 1){
                if(i == 0 && st == 0){
                    ways += rec(ind+1, ntlo, nthi, leftsum+i, rightsum, 0, ln);
                }else{
                    ways += rec(ind+1, ntlo, nthi, leftsum+i, rightsum, 1, ln+1);
                }
            }else{
                ways += rec(ind+1, ntlo, nthi, leftsum, rightsum+i, 1, ln+1);
            }
        }
        return dp[ind][tlo][thi][leftsum][rightsum][ln] = ways;
    }

    int countSymmetricIntegers(int low, int high) {
        lo = to_string(low);
        hi = to_string(high);
        if(hi.length()>lo.length()){
            int pre_len = hi.length()-lo.length();
            string temp = "";
            while(pre_len--){
                temp += "0";
            }
            lo = temp + lo;
        }
        memset(dp, -1, sizeof(dp));
        return rec(0, 1, 1, 0, 0, 0, 0);



    }
};