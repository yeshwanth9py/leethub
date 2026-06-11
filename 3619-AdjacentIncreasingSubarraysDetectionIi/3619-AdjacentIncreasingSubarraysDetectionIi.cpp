// Last updated: 6/11/2026, 11:17:28 AM
class Solution {
public:
    vector<int> incr;
    int n;
    bool check(int md){
        for(int i=0; i<n; i++){
            if(i+md<n && incr[i]>=md && incr[i+md]>=md){
                return 1;
            }
        }
        return 0;
    }

    int maxIncreasingSubarrays(vector<int>& nums) {
        n = nums.size();
        incr.resize(n, 1);
        for(int i=n-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                incr[i] = incr[i+1]+1;
            }else{
                incr[i] = 1;
            }
        }
        int lo = 0;
        int hi = n-1;
        int ans = -1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(check(mid)){
                ans = mid;
                lo = mid+1;
            }else{
                hi = mid-1;
            }
        }

        return ans;
    }
};