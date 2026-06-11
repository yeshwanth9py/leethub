// Last updated: 6/11/2026, 11:21:34 AM
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int i=0;
        int j = -1;
        int n = nums.size();
        unordered_map<int, long long> ump;
        long long cnt = 0;
        long long ans = 0;
        while(i<n){
            while(j+1<n && (cnt+1<=k)){
                j++;
                ump[nums[j]]++;
                if(ump[nums[j]] >= 2){
                    long long prev = ump[nums[j]]-1;
                    cnt += (prev);
                }
                // cout<<cnt<<endl;
            }
            if(cnt >= k){
                ans += (n-j);
            }

            if(i>j){
                j++;
                i = j-1;
            }else{
                ump[nums[i]]--;
                if(ump[nums[i]] >= 1){
                    long long cur = ump[nums[i]];
                    cnt -= cur;
                }
                // cout<<cnt<<endl;
                i++;
            }
        }
        return ans;

    }
};