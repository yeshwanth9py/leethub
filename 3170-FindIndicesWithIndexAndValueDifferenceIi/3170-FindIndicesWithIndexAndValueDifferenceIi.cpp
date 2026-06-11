// Last updated: 6/11/2026, 11:19:37 AM
class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int val) {
        long long mini = 1e18;
        long long maxi = -1e18;

        long long minind = -1;
        long long maxind = -1;

        long long n = nums.size();

        long long j=0;
        for(long long i=indexDifference; i<n; i++){
            if(mini>nums[j]){
                mini = nums[j];
                minind = j;
            }

            if(maxi<nums[j]){
                maxi = nums[j];
                maxind = j;
            }

            j++;

            if(nums[i]-val>=mini){
                return {(int) minind, (int) i};
            }else if(nums[i]+val<=maxi){
                return {(int) maxind, (int) i};
            }
        }

        return {-1, -1};
    }
};