// Last updated: 6/11/2026, 11:20:43 AM
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int i = 0;
        int j = -1;
        int n = nums.size();
        int tod = 0;
        int ans = 0;
        unordered_map<int, int> ump;
        for(int el: nums){
            ump[el]++;
        }
        tod = ump.size();

        unordered_map<int, int> temp;
        int nod = 0;

        while(i<n){
            while(j+1<n && nod+1<=tod){
                j++;
                temp[nums[j]]++;
                if(temp[nums[j]] == 1){
                    nod++;
                }
            }
            if(nod == tod){
                ans += (n-j);
            }
            if(j<i){
                i++;
                j = i-1;
            }else{
                temp[nums[i]]--;
                if(temp[nums[i]] == 0){
                    nod--;
                }
                i++;
            }
        }

        return ans;
    }
};