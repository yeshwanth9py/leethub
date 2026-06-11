// Last updated: 6/11/2026, 11:22:44 AM
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long cnt = 0;
        long long n = nums.size();
        long long ans = 0;
        for(long long i=0; i<n; i++){
            if(nums[i] == 0){
                cnt++;
            }else{
                if(cnt>0){
                    ans += ((cnt)*(cnt+1))/2;
                }
                cnt = 0;
            }
        }
        if(cnt>0){
            ans += (1LL*(cnt)*(cnt+1))/2;
        }

        return ans;
    }
};