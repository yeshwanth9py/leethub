// Last updated: 6/11/2026, 11:22:21 AM

using ll = long long;
class Solution {
public:
    bool cantake(ll numb, ll mask){
        // cout<<bitset<32>(numb)<<" "<<bitset<32>(mask)<<endl;
        for(ll i=0; i<32; i++){
            if(((numb & (1ll<<i))) && ((mask & (1ll<<i)))){
                return 0;
            }
        }
        return 1;
    }
    int longestNiceSubarray(vector<int>& nums) {
        ll n = nums.size();
        ll low = 0;
        ll high = -1;

        ll mask = 0;
        ll ans = 0;

        while(low<n){
            while(high+1<n && cantake(nums[high+1], mask)){
                high++;
                mask |= nums[high];
            }
            // cout<<low<<" "<<high<<endl;
            ans = max(ans, high-low+1);
            if(low>high){
                low++;
                high = low-1;
            }else{
                mask ^= nums[low];
                low++;
            }
        }

        return ans;
       
    }
};