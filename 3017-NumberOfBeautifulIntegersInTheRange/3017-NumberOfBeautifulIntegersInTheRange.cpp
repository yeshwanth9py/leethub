// Last updated: 6/11/2026, 11:20:27 AM
class Solution {
public:
    string low;
    string high;
    int n;
    int d;
    int dp[13][2][2][13][13][2][21];

    int rec(int ind, int tlo, int thi, int eve, int odd, int start, int numb){
        if(ind == n){
            if(numb%d == 0 && (eve == odd)) return 1;
            return 0;
        }
        if(dp[ind][tlo][thi][eve][odd][start][numb] != -1) return dp[ind][tlo][thi][eve][odd][start][numb];
        int l = 0;
        if(tlo == 1){
            l = low[ind]-'0';
        }

        int r = 9;
        if(thi == 1){
            r = high[ind]-'0';
        }

        int ways = 0;
        for(int i=l; i<=r; i++){
            int nstart = start;
            if(i != 0){
                nstart = 1;
            }

            int neve = eve;
            if(nstart && i%2 == 0){
                neve+=1;
            }
            int nodd = odd;
            if(nstart && i%2 == 1){
                nodd+=1;
            }

            int ntlo = tlo;
            if(i != l){
                ntlo = 0;
            }

            int nthi = thi;
            if(i != r){
                nthi = 0;
            }

            ways += rec(ind+1, ntlo, nthi, neve, nodd, nstart, ((numb*10)+i)%d);

        }

        return dp[ind][tlo][thi][eve][odd][start][numb] = ways;
    }

    int numberOfBeautifulIntegers(int l, int h, int k) {
        low = to_string(l);
        high = to_string(h);

        int exz = high.size()-low.size();
        string extra = "";
        while(exz--){
            extra.push_back('0');
        }

        low = extra+low;
        n = high.size();
        d = k;
        memset(dp, -1, sizeof(dp));

        return rec(0, 1, 1, 0, 0, 0, 0);


    }
};