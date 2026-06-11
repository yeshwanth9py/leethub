// Last updated: 6/11/2026, 11:27:15 AM

using ll = long long;
const ll mod = 1e9+7;
class Solution {
public:
    //o+e = o  e+e=e o+o=e
    int numOfSubarrays(vector<int>& arr) {
        ll n = arr.size();
        unordered_map<ll, ll> ump;
        ump[1] = 0;
        ump[2] = 0;
        ll sum = 0;
        ll ans = 0;
        for(ll i=0; i<n; i++){
            sum += arr[i];
            if(sum%2 == 0){
                ans += ump[1];
                ump[2]++;
            }else{
                ans++;
                ans += ump[2];
                ump[1]++;
            }
        }

        return ans%mod;
    }
};