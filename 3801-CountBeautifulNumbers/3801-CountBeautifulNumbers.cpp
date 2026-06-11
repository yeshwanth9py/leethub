// Last updated: 6/11/2026, 11:15:41 AM
class Solution {
public:
    string l;
    string r;
    int n;
    int temps;
    int dp[11][2][2][89][89][2];
    int rec(int idx, int tlo, int thi, int curp, int rems, int start){
        if(rems<0) return 0;
        if(idx==n){
            if(start) return 0;
            if(curp==0 && rems==0) return 1;
            return 0;
        }
        if(dp[idx][tlo][thi][curp][rems][start] != -1) return dp[idx][tlo][thi][curp][rems][start];

        int low=0;
        if(tlo){
            low = l[idx]-'0';
        }

        int high = 9;
        if(thi){
            high = r[idx]-'0';
        }

        int ans = 0;
        for(int i=low; i<=high; i++){
            int ntlo = (tlo && (i==low));
            int nthi = (thi && (i==high));
            int nstart = (start && (i==0));
            if(nstart == 1){
                ans += rec(idx+1, ntlo, nthi, 1, rems, 1);
            }else{
                ans += rec(idx+1, ntlo, nthi, (curp*i)%temps, rems-i, 0);
            }
        }

        return dp[idx][tlo][thi][curp][rems][start] = ans;
    }

    int beautifulNumbers(int a, int b) {
        l = to_string(a);
        r = to_string(b);

        int dif = r.size()-l.size();
        string rem = "";
        while(dif--){
            rem += "0";
        }

        l = rem+l;
        n = r.size();
        int ans = 0;
        for(int cs = 1; cs<=81; cs++){
            temps = cs;
            memset(dp, -1, sizeof(dp));
            ans += rec(0, 1, 1, 1, cs, 1);
        }

        return ans;
    }
};






