// Last updated: 6/11/2026, 11:38:47 AM
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        auto check = [&](int md, int nos){
            auto it = upper_bound(nums1.begin(), nums1.end(), md);
            int nol = 0;
            if(it != nums1.begin()){
                nol = (it-nums1.begin());
            }

            it = upper_bound(nums2.begin(), nums2.end(), md);
            if(it != nums2.begin()){
                nol += (it - nums2.begin());
            }

            return nol>=nos;
        };

        auto findbs = [&](int nol){
            int lo = -1e9;
            int hi = 1e9;
            int ans = -1;

            for(int i=0; i<60; i++){
                int mid = (lo+hi)/2;
                if(check(mid, nol)){
                    ans = mid;
                    hi = mid-1;
                }else{
                    lo = mid+1;
                }
            }
            return ans;
        };

        int tot = nums1.size() + nums2.size();
        if(tot%2 == 0){
            int n1 = findbs(tot/2);
            int n2 = findbs((tot/2) + 1);
            double ans = (1.0*(n1+n2))/2.0;
            return ans;
        }else{
            double n1 = findbs((tot+1)/2);
            return n1;
        }
    }
};

