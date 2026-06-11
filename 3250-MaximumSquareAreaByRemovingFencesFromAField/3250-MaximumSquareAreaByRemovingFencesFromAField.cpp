// Last updated: 6/11/2026, 11:19:07 AM

#define ll long long

class Solution {
public:
    const ll mod = 1e9+7;
    int maximizeSquareArea(int m, int n, vector<int>& h, vector<int>& v) {

        h.push_back(1);
        h.push_back(m);
        sort(h.begin(), h.end());

        v.push_back(1);
        v.push_back(n);
        sort(v.begin(), v.end());


        unordered_map<ll, ll> ump;
        for(ll i=0; i<h.size(); i++){
            for(ll j=i+1; j<h.size(); j++){
                ump[abs(h[j]-h[i])] = 1;
            }
        }


        ll ans = -1;
        for(ll i=0; i<v.size(); i++){
            for(ll j=i+1; j<v.size(); j++){
                ll val = abs(v[j]-v[i]);
                if(ump[val]>0){
                    ans = max(ans, val);
                }
            }
        }

        if(ans == -1) return -1;
        return ((ans*ans)%mod + mod)%mod;


    }
};