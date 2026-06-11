// Last updated: 6/11/2026, 11:12:42 AM
class Solution {
public:
    long long md = 1e5;
    long long maxProduct(vector<int>& arr) {
        vector<int> nums;
        for(int el: arr){
            if(el == 0) continue;
            nums.push_back(abs(el));
        }

        if(nums.size()<2) return 0;
        
        sort(nums.begin(), nums.end());
        
        long long n = nums.size();
        long long pro1 = (1LL*nums[0]*nums[1]);

        long long pro2 = (1LL*nums[n-1]*nums[n-2]);

        long long mas = max(pro1, pro2);

        long long ans = 1LL*mas*md;

        return ans;
        
    }
};