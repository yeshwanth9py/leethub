// Last updated: 6/11/2026, 11:27:12 AM
#define ll long long

class Solution {
public:
    int numSub(string s) {
        ll l = 0;
        ll ans = 0;
        ll mod = 1e9+7;
        for(ll i=0; i<s.size(); i++){
            if(s[i] == '1'){
                l++;
            }else{
                ans += (l*(l+1))/2;
                ans %= mod;
                l = 0;
            }
        }

        if(l) ans += (l*(l+1))/2;

        ans %= mod;
        return ans;
    }
};