// Last updated: 6/11/2026, 11:12:00 AM

#define ll long long
class Solution {
public:
    ll dp[(1LL<<14)];
    ll len[(1LL<<14)];
    ll median[(1LL<<14)];
    long long minMergeCost(vector<vector<int>>& lists) {
        ll n = lists.size();
        dp[0] = 0;
        for(ll mask=1; mask<(1LL<<(n)); mask++){
            dp[mask] = 1e18;
        }

        for(ll i=0; i<n; i++) dp[(1LL<<i)] = 0;

        for(ll mask=1; mask<(1LL<<(n)); mask++){
            vector<ll> arr;
            for(ll i=0; i<n; i++){
                if((mask&(1LL<<i)) != 0){
                   for(ll el: lists[i]) arr.push_back(el);
                }
            }
            len[mask] = arr.size();
            sort(arr.begin(), arr.end());    
            median[mask] = arr[(arr.size()-1)/2];
            // cout<<b<<" -> "<<len[mask]<<" -> "<<median[mask]<<endl;
        }

        for(ll mask=1; mask<(1LL<<(n)); mask++){
            for(ll s1 = 1; s1<mask; s1++){
                if((mask | s1) == mask){
                    ll s2 = ((mask^s1));
                    dp[mask] = min(dp[mask], len[s1] + len[s2] + abs(median[s1]-median[s2]) + dp[s1] + dp[s2]);
                }
            }
        }

        return dp[(1LL<<(n))-1];
    }
};