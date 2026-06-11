// Last updated: 6/11/2026, 11:30:20 AM
class Solution {
public:
    void merge2(vector<int> &nums, int lo, int hi, int lo2, int hi2){
        vector<int> ans(hi2-lo+1);
        int cur = 0;
        int s = lo;
        while(lo<=hi && lo2<=hi2){
            if(nums[lo]<=nums[lo2]){
                ans[cur] = nums[lo];
                cur++;
                lo++;
            }else{
                ans[cur] = nums[lo2];
                lo2++;
                cur++;
            }
        }
        while(lo<=hi){
            ans[cur] = nums[lo];
            cur++;
            lo++;
        }

        while(lo2<=hi2){
            ans[cur] = nums[lo2];
            lo2++;
            cur++;             
        }
        for(int i=0; i<ans.size(); i++){
            nums[i+s] = ans[i];
        }
    }

    void merge_sort(vector<int> &nums, int lo, int hi){
        if(lo>=hi) return;
        int mid = (lo+hi)/2;

        merge_sort(nums, lo, mid);
        merge_sort(nums, mid+1, hi);

        merge2(nums, lo, mid, mid+1, hi);

    }
    vector<int> sortArray(vector<int>& nums) {
        merge_sort(nums, 0, nums.size()-1);
        return nums;
    }
};