// Last updated: 6/11/2026, 11:21:52 AM
class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int pos = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] == k){
                pos = i;
                break;
            }
        }

        unordered_map<int, int> right_b;
        int bal = 0;
        right_b[0] = 1;
        for(int i=pos+1; i<n; i++){
            if(nums[i]>k){
                bal++;
            }else{
                bal--;
            }
            right_b[bal]++;
        }

        bal = 0;
        int ans = 0;
        for(int i=pos; i>=0; i--){
            if(nums[i]>k){
                bal++;
            }else if(nums[i]<k){
                bal--;
            }

            ans += right_b[-bal];
            ans += right_b[-bal+1];
        }

        return ans;

    }
};