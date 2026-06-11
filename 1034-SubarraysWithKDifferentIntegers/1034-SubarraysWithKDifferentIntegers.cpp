// Last updated: 6/11/2026, 11:29:56 AM
class Solution {
public:
    int count_sub_leq(vector<int> &nums, int k){
        int i = 0;
        int j = -1;
        int unq = 0;
        int n = nums.size();
        unordered_map<int, int> ump;
        int cnt = 0;
        while(i<n){
            while(j+1<n && unq+(ump[nums[j+1]]==0)<=k){
                j++;
                ump[nums[j]]++;  
                unq += (ump[nums[j]] == 1);
            }

            if(unq<=k){
                cnt += (j-i+1);
            }
            
            ump[nums[i]]--;  
            if(ump[nums[i]] == 0){
                unq-=1;
            }
            i++;
        }

        return cnt;
    }


    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return count_sub_leq(nums, k)-count_sub_leq(nums, k-1);
    }
};