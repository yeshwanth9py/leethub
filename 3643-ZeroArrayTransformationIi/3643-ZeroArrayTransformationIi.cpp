// Last updated: 6/11/2026, 11:17:09 AM
class Solution {
public:
    using ll = long long;
    bool check(int mid,vector<int>& nums,vector<vector<int>>& queries){
        int n = nums.size();
        vector<ll> dup(n, 0);
        for(int i=0; i<=mid; i++){
            int l = queries[i][0];
            int r = queries[i][1];
            int v = queries[i][2];
            dup[l] -= v;
            if(r+1<n){
                dup[r+1]+=v;
            }
        }
        for(int i=0; i<n; i++){
            if(i==0){
                if(dup[i]+nums[i]>0){
                    return false;
                }else{
                    continue;
                }
            }
            int num = dup[i-1]+dup[i]+nums[i];
            if(num>0){
                return false;
            }else{
                dup[i] += dup[i-1];
            }
        }
        return 1;
    }       

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();
        int lo = 0;
        int hi = m-1;
        bool flag = 0;
        for(int i=0; i<n; i++){
            if(nums[i] != 0){
                flag = 1;
                break;
            }
        }
        if(!flag) return 0;
        
        int ans = -1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(check(mid, nums, queries)){
                ans = mid;
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }
        if(ans == -1) return -1;
        return ans+1;
    }
};