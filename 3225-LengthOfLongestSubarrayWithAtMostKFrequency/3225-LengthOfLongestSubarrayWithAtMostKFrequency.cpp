// Last updated: 6/11/2026, 11:19:21 AM
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int maxf = 0;
        int i = 0;
        int j = -1;
        int n = nums.size();
        unordered_map<int, int> ump;
        multiset<int> ms;
        int ans = 0;
        while(i<n){
            while(j+1<n && maxf<=k){
                j++;
                ump[nums[j]]++;
                if(ms.find(ump[nums[j]]-1)!=ms.end()){
                    ms.erase(ms.find(ump[nums[j]]-1));
                }
                ms.insert(ump[nums[j]]);
                maxf = *ms.rbegin();
            }
            if(j>=i){
                if(maxf>k){
                    ans = max(ans, (j-i));
                }else{
                    ans = max(ans, j-i+1);
                }
            }

            if(i>j){
                i++;
                j = i-1;
            }else{
                ump[nums[i]]--;
                if(ms.find(ump[nums[i]]+1)!=ms.end()){
                    ms.erase(ms.find(ump[nums[i]]+1));
                }
                ms.insert(ump[nums[i]]);
                maxf = *(ms.rbegin());
                i++;
            }

        }
        return ans;
    }
};