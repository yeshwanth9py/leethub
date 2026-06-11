// Last updated: 6/11/2026, 11:31:04 AM
class Solution {
public:
    vector<int> arr1, arr2;
    vector<vector<int>> dp;
    int rec(int ind, int isprevsw){
        if(ind == arr1.size()){
            return 0;
        }

        if(dp[ind][isprevsw]!=-1){
            return dp[ind][isprevsw];
        }

        int pel1 = ind-1>=0?arr1[ind-1]:-1;
        int pel2 = ind-1>=0?arr2[ind-1]:-1;

        if(isprevsw == 1){
            pel1 = ind-1>=0?arr2[ind-1]:-1;
            pel2 = ind-1>=0?arr1[ind-1]:-1;
        }
        //noswap
        int minop = 1e9;
        if(arr1[ind]>pel1 && arr2[ind]>pel2){
            minop = min(minop, 0+rec(ind+1, 0));
        }
        //swap
        if(arr2[ind]>pel1 && arr1[ind]>pel2){
            minop = min(minop, 1+rec(ind+1, 1));
        }
        return dp[ind][isprevsw] = minop;
    }


    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        arr1 = nums1;
        arr2 = nums2;
        dp.assign(nums1.size(), vector<int>(2, -1));
        return rec(0, 0);
    }
};