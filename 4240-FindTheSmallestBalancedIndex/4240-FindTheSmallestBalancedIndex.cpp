// Last updated: 6/11/2026, 11:10:13 AM
class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        long long n = nums.size();
        vector<long long> pres(n, 0);
        vector<long long> sufpro(n, 1);

        for(long long i=0; i<n; i++){
            pres[i] = (i-1>=0?pres[i-1]:0) + nums[i];
        }
        int ans = -1;
        if(n-2>=0 && pres[n-2] == 1) ans = n-1;
        for(long long i=n-1; i>=0; i--){
            if(i+1<n && log10(nums[i]) + log10(sufpro[i+1]) > 15) return ans;
            sufpro[i] = (i+1<n?sufpro[i+1]:1) * nums[i];
            long long ls = 0;
            if(i-2>=0){
                ls = pres[i-2];
            }
            if(sufpro[i]==ls){
                ans = i-1;
            }
            if(sufpro[i] > ls) return ans;
            if(sufpro[i]>1e15) return ans;
        }

       
        return -1;
        
    }
};