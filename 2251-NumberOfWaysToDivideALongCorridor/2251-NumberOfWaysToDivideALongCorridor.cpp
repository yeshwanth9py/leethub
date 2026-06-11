// Last updated: 6/11/2026, 11:23:44 AM
class Solution {
public:
    const int mod = 1e9+7;
    int numberOfWays(string s) {
        vector<int> pos;
        for(int i=0; i<s.size(); i++){
            char ch = s[i];
            if(ch == 'S'){
                pos.push_back(i);
            }
        }

        if(pos.size()%2 != 0 || pos.size() == 0){
            return 0;
        }

        int n = pos.size();
        int ans = 1;
        for(int i=1; i<n; i=i+2){
            if(i+1>=n) break;
            int ways = (pos[i+1]-pos[i])%mod;
            ans = (1LL*ans*ways)%mod;
            if(ans<0){
                ans += mod;
            }
        }

        return ans;


    }
};