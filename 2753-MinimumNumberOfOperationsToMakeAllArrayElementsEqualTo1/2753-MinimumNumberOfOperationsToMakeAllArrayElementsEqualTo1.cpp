// Last updated: 6/11/2026, 11:21:00 AM
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int g = 0;
        int n1 = 0;
        for(int i=0; i<n; i++){
            g = __gcd(g, nums[i]);
            if(nums[i] != 1){
                n1++;
            }
        }

        if(n1 != n){
            return n1;
        }

        if(g == 1){
            int minans = 1e9;
            for(int i=0; i<n; i++){
                int cur = nums[i];
                for(int j=i; j<n; j++){
                    cur = __gcd(cur, nums[j]);
                    if(cur == 1){
                        minans = min(minans, j-i+n-1);
                        break;
                    }
                }
            }

            return minans;

        }
        return -1;
    }
};