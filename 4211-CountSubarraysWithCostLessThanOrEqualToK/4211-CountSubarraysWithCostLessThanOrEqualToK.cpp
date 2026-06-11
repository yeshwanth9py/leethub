// Last updated: 6/11/2026, 11:10:36 AM
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long i = 0;
        long long j=-1;
        multiset<long long> ms;
        long long n = nums.size();

        long long maxtn = -1e18;
        long long mintn = 1e18;
        long long ans = 0;
        while(i<n){
            // cout<<max(maxtn, nums[j+1])-min(mintn, nums[j+1])*(j+1-i+1)<<endl;
            while(j+1<n && (max(maxtn, 1LL*nums[j+1])-min(mintn, 1LL*nums[j+1]))*(j+1-i+1)<=k){
                j++;
                // cout<<i<<" "<<j<<",, ";
                ms.insert(nums[j]);
                maxtn = max(maxtn, 1LL*nums[j]);
                mintn = min(mintn, 1LL*nums[j]);
            }
            if(j-i+1>0){
                // cout<<i<<" "<<j<<", ";
                ans += j-i+1;
            }

            if(i>j){
                i++;
                j=i-1;
                maxtn = -1e18;
                mintn = 1e18;
                ms.clear();
            }else{
                ms.erase(ms.find(nums[i]));
                if(ms.size()>0){
                    maxtn = *ms.rbegin();
                    mintn = *ms.begin();
                }else{
                    maxtn = -1e18;
                    mintn = 1e18;
                }
                i++;
            }
        }

        return ans;
    }
};