// Last updated: 6/11/2026, 11:31:44 AM
class Solution {
public:
    int n;
    bool check(int md, vector<int> &nums, int k){
        int cnt = 0;
        for(int i=0; i<n; i++){
            int el = nums[i];
            int fel = nums[i]+md;
            // if(fel>nums.back()) continue;
            auto it = upper_bound(nums.begin(), nums.end(), fel);
            if(it==nums.begin()) continue;
            it--;
            int ind = it-nums.begin();
            if(ind-i>0) cnt += (ind-i);
        }
        return cnt>=k;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        n = nums.size();
        sort(nums.begin(), nums.end());
        int lo = 0;
        int hi = nums[n-1] - nums[0];
        int ans = 0;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(check(mid, nums, k)){  
                ans = mid;
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }

        return ans;
    }
};