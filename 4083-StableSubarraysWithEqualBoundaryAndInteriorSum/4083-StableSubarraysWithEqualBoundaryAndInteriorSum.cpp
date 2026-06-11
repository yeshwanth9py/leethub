// Last updated: 6/11/2026, 11:12:58 AM
class Solution {
public:
    long long countStableSubarrays(vector<int>& arr) {
        map<pair<long long, long long>, long long> ump;
        long long cs = 0;
        long long n = arr.size();
        long long ans = 0;
        
        
        for(long long i=0; i<n; i++){
            cs += arr[i];
            if(ump.find({cs-(2*arr[i]), arr[i]}) != ump.end()){
                ans += ump[{cs-(2*arr[i]), arr[i]}];
            }
            if(i-1>=0) ump[{cs-arr[i], arr[i-1]}]++;
            // cout<<ans<<" ";
        }

        return ans;
    }
};