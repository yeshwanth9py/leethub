// Last updated: 6/11/2026, 11:19:36 AM
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long cnt1 = 0;
        long long x=0;
        for(int el: nums1){
            if(el == 0){
                cnt1++;
            }else{
                x += el;
            }
        }
        
        long long cnt2 = 0;
        long long y = 0;
        for(int el: nums2){
            if(el == 0){
                cnt2++;
            }else{
                y += el;
            }
        }

        long long a = x-y;
        // cout<<a<<endl;
        //x+a = y;
        if(cnt1 == 0 && cnt2 == 0){
            if(a == 0) return x;
            return -1;
        }else if(cnt2 == 0){
            if(a+cnt1<=0){
                return y;
            }
            return -1;
        }else if(cnt1 == 0){
            if(a>=cnt2){
                return x;
            }
            return -1;
        }

        long long lo = cnt1;
        long long hi = cnt2+cnt1+abs(a)+1;
        long long ans = -1;
        while(lo<=hi){
            long long mid = (lo+hi)/2;
            if(mid+a>=cnt2){
                ans = mid;
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }
        // cout<<x<<" "<<ans<<endl;
        return x+ans;

    }
};