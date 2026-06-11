// Last updated: 6/11/2026, 11:20:59 AM

using ll = long long;
ll mod = 1e9+7;
class Solution {
public:
    string l, r;
    int maxsum;
    int minsum;
    ll dp[24][2][2][401];
    ll rec(int ind, int tlo, int thi, int dsum){
        
        // cout<<ind<<" ";
        if(ind == r.length()){
            if(dsum>maxsum || dsum<minsum){
                return 0;
            }
            return 1;
        }
        if(dp[ind][tlo][thi][dsum]!=-1){
            return dp[ind][tlo][thi][dsum];
        }

        int st = 0;
        if(tlo == 1){
            st = l[ind]-'0';
        }

        int en = 9;
        if(thi == 1){
            en = r[ind]-'0';
        }

        ll ways = 0;
        for(int i=st; i<=en; i++){
            int ntlo = tlo;
            int nthi = thi;
            if(i!=st) ntlo = 0;
            if(i!=en) nthi = 0;
            ways += rec(ind+1, ntlo, nthi, dsum+i)%mod;
            ways %= mod;
        }
        return dp[ind][tlo][thi][dsum] = ways;
    }

    int count(string num1, string num2, int min_sum, int max_sum) {
        l = num1;
        r = num2;
        int diff = r.length()-l.length();
        string temp = "";
        while(diff--){
            temp += "0";
        }
        l = temp + l;
        // cout<<l<<" "<<r<<endl;
        this->minsum = min_sum;
        this->maxsum = max_sum;
        memset(dp, -1, sizeof(dp));
        return rec(0, 1, 1, 0);
    }   
};