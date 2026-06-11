// Last updated: 6/11/2026, 11:23:05 AM
using ll = long long;
class Solution {
public:
    long long appealSum(string s) {
        
        ll ans = 0;
        ll n = s.size();
        for(char ch='a'; ch<='z'; ch++){
            ll last = -1;
            ll contrib = n*(n+1)/2;
            for(ll i=0; i<n; i++){
                if(s[i] == ch){
                    ll len = i-last-1;
                    ll sub_nc  = (len+1)*(len)/2;
                    contrib -= sub_nc;
                    last = i;
                }
            }
            ll len = n-last-1;
            ll sub_nc = (len+1)*(len)/2;
            contrib -= sub_nc;
            ans += contrib;
        }
        return ans;
    }
};