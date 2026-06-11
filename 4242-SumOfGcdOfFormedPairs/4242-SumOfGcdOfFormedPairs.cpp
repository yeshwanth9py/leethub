// Last updated: 6/11/2026, 11:10:12 AM
class Solution {
public:
    long long gcd(long long a, long long b){
        if(b == 0 || a==0){
            return a^b;
        }
        if(a>b){
            return gcd(b, a%b);
        }else{
            return gcd(a, b%a);
        }
    }
    
    long long gcdSum(vector<int>& nums) {
        long long mx = -1e18;
        long long n = nums.size();
        vector<long long> pre;
        for(long long i=0; i<n; i++){
            mx = max(mx, 1LL*nums[i]);
            long long g = gcd(mx, nums[i]);
            pre.push_back(g);
        }

        sort(pre.begin(), pre.end());

        long long i=0;
        long long j=pre.size()-1;
        long long ans = 0;
        while(i<j){
            ans += gcd(pre[i], pre[j]);
            i++;
            j--;
        }

        return ans;
    }
};