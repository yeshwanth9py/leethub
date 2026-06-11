// Last updated: 6/11/2026, 11:35:32 AM
class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int lo = 0;
        int hi = n-1;
        int ans = arr[0];
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(arr[mid]>=ans){
                lo = mid+1;
            }else{
                ans = arr[mid];
                hi = mid-1;
            }
        }

        return ans;
    }
};