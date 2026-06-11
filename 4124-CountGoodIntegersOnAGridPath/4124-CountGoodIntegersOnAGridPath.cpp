// Last updated: 6/11/2026, 11:12:24 AM
class Solution {
public:
    vector<long long> s; //0 - 6
    string low;
    string high;
    long long dp[17][2][2][7][10];
    long long rec(long long ind, long long tlo, long long thi, long long dind, long long prev){
        if(ind == 16){
            if(dind == 7) return 1;
            return 0;
        }
        if(dp[ind][tlo][thi][dind][prev] != -1) return dp[ind][tlo][thi][dind][prev];

        long long l = 0;
        long long h = 9;
        if(tlo){
            l = low[ind]-'0';
        }
        if(thi){
            h = high[ind]-'0';
        }

        long long ans = 0;
        for(long long i=l; i<=h; i++){
            if(ind == s[dind]){
                if(i<prev) continue;
                ans += rec(ind+1, (tlo && i==l) , (thi && i == h), dind+1, i);
            }else{
                ans += rec(ind+1, (tlo && i==l) , (thi && i == h), dind, prev);
            }
        }

        return dp[ind][tlo][thi][dind][prev] = ans;
    }
    
    long long countGoodIntegersOnPath(long long l, long long r, string dir) {
        vector<vector<long long>> arr(4, vector<long long>(4, 0));
        memset(dp, -1, sizeof(dp));
        long long v = 0;
        for(long long i=0; i<4; i++){
            for(long long j=0; j<4; j++){
                arr[i][j] = v;
                v++;
            }
        }
        
        long long cr = 0;
        long long cc = 0;
        s.push_back(arr[cr][cc]);
        for(long long i=0; i<dir.size(); i++){
            if(dir[i] == 'D'){
                cr++;
            }else{
                cc++;
            }
            s.push_back(arr[cr][cc]);
        }

        low = to_string(l);
        high = to_string(r);

        long long dif = 16 - low.size();
        string temp = "";
        while(dif--){
            temp += "0";
        }
        low = temp + low;
        
        dif = 16-high.size();
        temp = "";
        while(dif--){
            temp += "0";
        }
        high = temp + high;

        return rec(0, 1, 1, 0, 0);
        
    }
};