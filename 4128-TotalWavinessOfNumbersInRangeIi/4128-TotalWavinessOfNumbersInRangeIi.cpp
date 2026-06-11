// Last updated: 6/11/2026, 11:12:19 AM
class Solution {
public:
    long long dp[18][2][2][10][10][2][2];
    long long dp2[18][2][2][2];
    string l;
    string h;
    long long rec2(long long idx, long long tlo, long long thi, long long st){
        if(idx == h.size()) return st==0;
        if(dp2[idx][tlo][thi][st] != -1) return dp2[idx][tlo][thi][st];

        long long low = 0;
        if(tlo){
            low = l[idx]-'0';
        }

        long long high = 9;
        if(thi){
            high = h[idx]-'0';
        }

        long long ans = 0;
        for(long long i=low; i<=high; i++){
            long long ntlo = (tlo && (i==low));
            long long nthi = (thi && (i == high));
            long long nst = (st && (i == 0));

            ans += rec2(idx+1, ntlo, nthi, nst);
        }

        return dp2[idx][tlo][thi][st] = ans;
    }

    long long rec(long long idx, long long tlo, long long thi, long long p, long long pp, long long st, long long pst){
        if(idx == h.size()){
            return 0;
        }
        if(dp[idx][tlo][thi][p][pp][st][pst] != -1) return dp[idx][tlo][thi][p][pp][st][pst];
        long long low = 0;
        if(tlo){
            low = l[idx]-'0';
        }

        long long high = 9;
        if(thi){
            high = h[idx]-'0';
        }

        long long ans = 0;
        for(long long i=low; i<=high; i++){
            long long ntlo = (tlo && (i==low));
            long long nthi = (thi && (i == high));
            long long nst = (st && (i == 0));
            long long current = 0;
            if(st==0 && pst==0){
                if((p>pp && p>i) || (p<pp && p<i)){
                    current = rec2(idx+1, ntlo, nthi, nst);
                }
            }
            ans += current + rec(idx+1, ntlo, nthi, i, p, nst, st);
        }

        return dp[idx][tlo][thi][p][pp][st][pst] = ans;
    }

    long long totalWaviness(long long num1, long long num2) {
        l = to_string(num1);
        h = to_string(num2);
        long long dif = h.size()-l.size();
        string temp = "";
        while(dif--){
            temp += "0";
        }
        l = temp + l;

        memset(dp, -1, sizeof(dp));
        memset(dp2, -1, sizeof(dp2));

        return rec(0, 1, 1, 0, 0, 1, 1);
    }
};