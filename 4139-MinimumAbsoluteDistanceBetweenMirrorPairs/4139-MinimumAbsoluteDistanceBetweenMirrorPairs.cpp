// Last updated: 6/11/2026, 11:12:05 AM
class Solution {
public:
    int reverse(int num){
        int rnum = 0;
        while(num){
            rnum = rnum*10 + num%10;
            num = num/10;
        }
        return rnum;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> ump;
        int n = nums.size();
        int ans = 1e9;
        for(int i=n-1; i>=0; i--){
            if(ump.find(reverse(nums[i])) != ump.end()){
                ans = min(ans, ump[reverse(nums[i])] - i );
            }
            // while(nums[i]>0 && nums[i]%10 == 0){
            //     nums[i] = nums[i]/10;
            // }
            ump[nums[i]] = i;
        }

        if(ans == 1e9) return -1;
        return ans;
    }
};