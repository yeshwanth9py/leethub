// Last updated: 6/11/2026, 11:38:12 AM
class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n = arr.size();

        int lo = 0;
        int hi = n-1;
        int ansp = 0;

        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(arr[mid]>=arr[0]){
                ansp = mid;
                lo = mid+1;
            }else{
                hi = mid-1;
            }
        }

        if(arr[ansp] == target) return ansp;
        // cout<<ansp<<endl;

        if(target>=arr[0] && target<=arr[ansp]){
            lo = 0;
            hi = ansp;
            int ans = 0;
            while(lo<=hi){
                int mid = (lo+hi)/2;
                if(arr[mid]>target){
                    hi = mid-1;
                }else if(arr[mid] == target){
                    return mid;
                }else{
                    lo = mid+1;
                }
            }
            return -1;
        }else{
            lo = ansp+1;
            hi = n-1;
            int ans = 0;
            while(lo<=hi){
                int mid = (lo+hi)/2;
                if(arr[mid]>target){
                    hi = mid-1;
                }else if(arr[mid] == target){
                    return mid;
                }else{
                    lo = mid+1;
                }
            }
            return -1;
        }
    }
};