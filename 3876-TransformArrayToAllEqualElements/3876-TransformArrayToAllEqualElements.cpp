// Last updated: 6/11/2026, 11:14:59 AM
class Solution {
public:
    bool canmakeone(vector<int>& nums, int k){
        int i = 0;
        int n = nums.size();
        int op = 0;
        while(i<nums.size()){
            while(i<n && nums[i] == 1){
                i++;
            }
            if(i<n){
                if(i+1<n){
                    op++;
                    if(nums[i+1]==1){
                        nums[i+1] = -1;
                        i = i+1;
                    }else{
                        i=i+2;
                    }
                }else{
                    return 0;
                }
            }
        }
        return op<=k;
    }
    
    bool canmakemone(vector<int>& nums, int k){
        int i = 0;
        int n = nums.size();
        int op = 0;
        while(i<nums.size()){
            while(i<n && nums[i] == -1){
                i++;
            }
            if(i<n){
                if(i+1<n){
                    op++;
                    if(nums[i+1] == -1){
                        nums[i+1] = 1;
                        i=i+1;
                    }else{
                        i=i+2;
                    }
                }else{
                    return 0;
                }
            }
        }
        return op<=k;
    }
    
    bool canMakeEqual(vector<int>& nums, int k) {
        vector<int> dup = nums;
        return canmakeone(nums, k) || canmakemone(dup, k);
    }
};