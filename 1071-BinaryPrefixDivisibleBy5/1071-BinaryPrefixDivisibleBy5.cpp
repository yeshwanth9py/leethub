// Last updated: 6/11/2026, 11:29:41 AM
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<bool> cnt(n, 0);
        for(int i=0; i<n; i++){
            ans = ans*2 + nums[i];
            if(ans%5 == 0){
                cnt[i] = 1;
            }
            ans = ans%5;
        }

        return cnt;
    }
};