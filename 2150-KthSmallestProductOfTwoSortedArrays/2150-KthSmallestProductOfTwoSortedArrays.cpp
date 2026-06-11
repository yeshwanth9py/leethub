// Last updated: 6/11/2026, 11:24:35 AM
using ll = long long;

class Solution {
public:
    bool check(ll pro, ll k, vector<int>& nums1, vector<int>& nums2){
        ll totless = 0;
        for(ll i=0; i<nums1.size(); i++){
            ll a = nums1[i];
            // cout<<a<<" ";
            if(a>=0){
                ll l = 0;
                ll h = nums2.size()-1;
                ll ans = -1;
                while(l<=h){
                    ll mid = (l+h)/2;
                    if(nums2[mid]*a <= pro){
                        ans = mid;
                        l = mid+1;
                    }else{
                        h = mid-1;
                    }
                }
                // cout<<ans<<", ";
                totless += (ans+1);
            }else{
                ll l = 0;
                ll h = nums2.size()-1;
                ll ans = nums2.size();
                while(l<=h){
                    ll mid = (l+h)/2;
                    if(1LL*nums2[mid]*a <= pro){
                        ans = mid;
                        h = mid-1;
                    }else{
                        l = mid+1;
                    }
                }
                // . . t t t
                // cout<<ans<<", ";
                totless += (nums2.size()-ans);
            }
            
        }

        return totless>=k;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        ll lo = -1e10;
        ll hi = 1e10;

        ll ans = -1;
        while(lo<=hi){
            ll mid = (lo+hi)/2;
            // cout<<mid<<"\n";
            if(check(mid, k, nums1, nums2)){
                hi = mid-1;
                ans = mid;
            }else{
                lo = mid+1;
            }
        }

        return ans;
    }

};