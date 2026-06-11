// Last updated: 6/11/2026, 11:25:37 AM
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        int answer = 0;
        for(int i=0; i<nums1.size(); i++){
            int el = nums1[i];
            int lo = 0;
            int hi = n-1;
            int ans = -1;
            while(lo<=hi){
                int mid = (lo+hi)/2;
                if(nums2[mid]>=el){
                    ans = mid;
                    lo = mid+1;
                }else{
                    hi = mid-1;
                }
            }
            // cout<<el<<" "<<ans<<endl;

            if(ans<i) continue;
            answer = max(answer, ans-i);
        }

        return answer;
    }
};