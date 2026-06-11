// Last updated: 6/11/2026, 11:31:10 AM
class Solution {
public:
    unordered_map<int, int> ump;
    string l;
    int dp[9][2][2][3];
    //isg = 1, 0, 2 
    int rec(int ind, int thi, int started, int isg){
        if(ind == l.size()){
            if(isg == 2) return 1;
            return 0;
        }

        int lo = 0;
        int hi = 9;
        if(thi){
            hi = l[ind]-'0';
        }

        if(dp[ind][thi][started][isg] != -1) return dp[ind][thi][started][isg];

        int ans = 0;
        for(int i=lo; i<=hi; i++){
            int nthi = (thi && (i==hi));
            int nisg = isg;

            if(nisg == 1 || nisg == 2){
                if(ump[i] == -1){
                    nisg = 0;
                }
                else if(ump[i] != i){
                    nisg = 2;
                }
            }

            ans += rec(ind+1, nthi, (started && (i == 0)), nisg);
        }

        return dp[ind][thi][started][isg] = ans;
    }

    int rotatedDigits(int n) {
        ump[0] = 0;
        ump[1] = 1;
        ump[8] = 8;

        ump[2] = 5;
        ump[5] = 2;
        ump[6] = 9;
        ump[9] = 6;

        ump[3] = -1;
        ump[4] = -1;
        ump[7] = -1;

        l = to_string(n);
        memset(dp, -1, sizeof(dp));

        return rec(0, 1, 1, 1);
    }
};