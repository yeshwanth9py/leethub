// Last updated: 6/11/2026, 11:11:07 AM

#define ll long long
class Solution {
public:
    bool check(int mid, vector<int> &nums){
        ll op = 0;
        for(int el: nums){
            op += ceil(1.0*el/mid);
        }
        return op<=(1LL*mid*mid);
    }
    
    int minimumK(vector<int>& nums) {
        int lo = 1;
        int hi = 1e9;
        int ans = hi;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(check(mid, nums)){
                ans = mid;
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }

        return ans;
    }
};