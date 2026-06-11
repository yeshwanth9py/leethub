// Last updated: 6/11/2026, 11:34:33 AM
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0;
        int cnt2 = 0;
        int el1 = nums[0];
        int el2 = nums[0];
        
        for(int el: nums){
            if(el == el1){
                cnt1++;
            }else if(el == el2){
                cnt2++;
            }

            else if(cnt1 == 0 || cnt2 == 0){
                if(cnt1 == 0){
                    cnt1 = 1;
                    el1 = el;
                }else if(cnt2 == 0){
                    cnt2 = 1;
                    el2 = el;
                }
            }else {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0;
        cnt2 = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == el1){
                cnt1++;
            }else if(nums[i] == el2){
                cnt2++;
            }
        }
        vector<int> ans;
        if(cnt1 > nums.size()/3){
            ans.push_back(el1);
        }
        if(cnt2>nums.size()/3){
            ans.push_back(el2);
        }
        return ans;


    }
};