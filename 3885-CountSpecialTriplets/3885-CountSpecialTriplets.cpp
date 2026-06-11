// Last updated: 6/11/2026, 11:14:54 AM
class Solution {
public:
    const long long mod = 1e9+7;
    int specialTriplets(vector<int>& nums) {
        unordered_map<long long, long long> fut;
        unordered_map<long long, long long> past;
        long long n = nums.size();
        for(long long i=0; i<n; i++){
            fut[nums[i]]++;
        }

        long long ans = 0;
        for(long long i=0; i<n; i++){
            fut[nums[i]]--;
            long long sch = 2*nums[i];
            // cout<<" "<<(past.count(sch))<<" "<<(fut.count(sch))<<endl;
            if((past.count(sch)>0) && (fut.count(sch)>0)){
                ans += 1LL*(past[sch])*(fut[sch]);
                ans %= mod;
                ans = (ans+mod)%mod;
            }
            past[nums[i]]++;
        }

        return ans;
    }
};