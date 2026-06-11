// Last updated: 6/11/2026, 11:29:25 AM
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int memo[10001];
    MountainArray* arr;

    int cache_check(int idx){
        if(memo[idx]!=-1){
            return memo[idx];
        }
        return memo[idx] = arr->get(idx);
    }

    bool check(int mid, MountainArray &arr){
        if(cache_check(mid)>cache_check(mid+1)){
            return 1;
        }
        return 0;
    }

    bool check1(int mid, int target, MountainArray &arr){
        if(cache_check(mid)>=target){
            return 1;
        }
        return 0;
    }

    bool check2(int mid, int target, MountainArray &arr){
        if(cache_check(mid)<=target){
            return 1;
        }
        return 0;
    }

    int findInMountainArray(int target, MountainArray &arr) {
        //finding peak
        memset(memo, -1, sizeof(memo));
        this->arr = &arr;
        int n = arr.length();
        int lo = 1;
        int hi = n-2;
        int pk = -1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(check(mid, arr)){  //arr[mid]>arr[mid+1]
                pk = mid;
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }

        //inc array search
        lo = 0;
        hi = pk;
        int ans = -1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(check1(mid, target, arr)){
                ans = mid;
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }

        if(ans!=-1 && cache_check(ans) == target){
            return ans;
        }

        //right arr search
        lo = pk+1;
        hi = n-1;
        ans = -1;

        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(check2(mid, target, arr)){
                ans = mid;
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }

        if(ans!=-1 && cache_check(ans) == target){
            return ans;
        }

        return -1;
    }
};