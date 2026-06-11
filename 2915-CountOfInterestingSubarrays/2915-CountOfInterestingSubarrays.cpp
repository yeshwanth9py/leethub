// Last updated: 6/11/2026, 11:20:34 AM
class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long ans = 0;
        int n = nums.size();
        int cursum = 0;
        unordered_map<int, int> ump;
        ump[0] = 1;
        for(int i=0; i<n; i++){
            cursum += (nums[i]%modulo == k);
            int rem = cursum%modulo;

            if(rem<0){
                rem += modulo;
            }

            if(ump.find((rem-k+modulo)%modulo) != ump.end()){
                ans += ump[(rem-k+modulo)%modulo];
            }
            ump[rem]++;
        }
        return ans;
    }
};