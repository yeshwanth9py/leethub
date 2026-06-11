// Last updated: 6/11/2026, 11:12:48 AM
class Solution {
public:
    string l;
    string r;
    int n;
    long long dp[19][2][2][3][2][270];
    long long rec(int ind, int tlo, int thi, int started, int is_odd, int sum_dif){  //odd-eve
        if(ind == n){
            if(started == 2 && sum_dif == 0) return 1;
            return 0;
        }

        if(dp[ind][tlo][thi][started][is_odd][sum_dif+135] != -1) return dp[ind][tlo][thi][started][is_odd][sum_dif+135];
        int low = 0;
        int high = 9;
        if(tlo){
            low = l[ind]-'0';
        }
        if(thi){
            high = r[ind]-'0';
        }

        long long ans = 0;
        for(int i=low; i<=high; i++){
            int nstarted = started;
            if(i != 0 && started == 0){
                nstarted++;
            }else if(started==1){
                nstarted++;
            }
            int nsumd = sum_dif;

            int nis_odd = !is_odd;
            if(started == 0 && nstarted == 1){
                nis_odd = 1;
            }

            if(nis_odd){
                nsumd += i;
            }else{
                nsumd -= i;
            }

            ans += rec(ind+1, (tlo&&(i==low)), (thi&&(i==high)), nstarted, nis_odd, nsumd);
        }

        return dp[ind][tlo][thi][started][is_odd][sum_dif+135] = ans;
    }

    long long countBalanced(long long low, long long high) {
        l = to_string(low);
        r = to_string(high);
        int dif = r.size()-l.size();
        string temp = "";
        while(dif--){
            temp += "0";
        }
        l = temp + l;

        n = r.size();
        memset(dp, -1, sizeof(dp));
        return rec(0, 1, 1, 0, 0, 0);
    }
};