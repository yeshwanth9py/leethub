// Last updated: 6/11/2026, 11:14:02 AM
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k, int m) {
        long long n = nums.size();
        long long i = 0;
        long long j = -1;
        long long je = -1;

        long long dist = 0;
        long long noefgem = 0;

        unordered_map<long long, long long> ump;

        long long ans = 0;

        while(i<n){
            while(j+1<n && ((dist<k) || (dist == k && noefgem<k)) ){
                j++;
                ump[nums[j]]++;
                if(ump[nums[j]] == 1){
                    dist++;
                }
                if(ump[nums[j]] == m){
                    noefgem++;
                }
            }
            je = max(je, j);
            while(je+1<n && dist+(ump[nums[je+1]] == 0) <= k){
                je++;
            }

            if(dist == k && noefgem == k){
                ans += (je-j+1);
            }

            if(i>j){
                i++;
                j=i-1;
                je=i-1;
            }else{
                ump[nums[i]]--;
                if(ump[nums[i]] == 0){
                    dist--;
                }
                if(ump[nums[i]] == m-1){
                    noefgem--;
                }
                i++;
            }
        }

        return ans;



    }
};