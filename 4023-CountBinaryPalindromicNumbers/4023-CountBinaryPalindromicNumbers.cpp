// Last updated: 6/11/2026, 11:13:46 AM
class Solution {
public:
    string s;
    int dp[61][61][2][2][2][2];
    int m;
    int rec(int idx, int lidx, int tlo, int thi, int st, int rig){
        // cout<<idx<<" "<<lidx<<" "<<tlo<<" "<<thi<<" "<<st<<" "<<rig<<endl;
        if(idx>=lidx){
            if(rig == 1 && thi == 1) return 0;
            // cout<<rig<<" "<<thi<<" "<<temp<<endl;
            return 1;
        }

        int l = -1;
        int h = -1;
        if(tlo == 0){
            l = 0;
        }else{
            l = s[idx]-'0';
        }

        if(thi == 0){
            h = 1;
        }else{
            h = s[idx]-'0';
        }

        if(dp[idx][lidx][tlo][thi][st][rig]!=-1) return dp[idx][lidx][tlo][thi][st][rig];

        int cnt = 0;
        for(int i=l; i<=h; i++){
            int nst = st;
            if(i != 0) nst = 1;
            int nrig = rig;
            // int nlenn = lenn;
            int nlidx = lidx;
            if(nst){
                if(thi==1 && s[lidx-1]-'0' < i){
                    nrig = 1;
                }
                if(thi == 1 && s[lidx-1]-'0' > i){
                    nrig = 0;
                }
                nlidx = lidx-1;
            }
            // temp += to_string(i);
            if(thi == 1 && i!=h){
                cnt += rec(idx+1,nlidx, tlo, 0, nst, nrig);
            }else if(thi == 1){
                cnt += rec(idx+1,nlidx, tlo, 1, nst, nrig);
            }else{
                cnt += rec(idx+1,nlidx, tlo, 0, nst, nrig);
            }
            // temp.pop_back();
        }
        return dp[idx][lidx][tlo][thi][st][rig] = cnt;
    }

    
    int countBinaryPalindromes(long long n) {
        s = "";
        if(n== 0) return 1;
        int len = log2(n) + 1;
        
        for(int i=len-1; i>=0; i--){
            if((n&(1LL<<i))){
                s += '1';
            }else{
                s += '0';
            }
        }
        m = s.size();
        // cout<<s<<endl;
        // string temp = "";
        memset(dp, -1, sizeof(dp));
        return rec(0, m, 0, 1, 0, 0);
    }
};