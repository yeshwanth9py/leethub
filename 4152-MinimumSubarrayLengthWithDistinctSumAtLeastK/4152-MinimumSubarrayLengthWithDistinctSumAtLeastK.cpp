// Last updated: 6/11/2026, 11:11:30 AM
class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        int ans = 1e9;
        int i=0;
        int j=-1;
        int cs = 0;
        int n = nums.size();
        while(i<n){
            while(j+1<n && cs<k){
                j++;
                ump[nums[j]]++;
                if(ump[nums[j]] == 1){
                    cs += nums[j];
                }
            }

            if(j-i+1>0 && cs>=k){
                ans = min(ans, j-i+1);
            }

            if(i>j){
                i++;
                j=i-1;
            }else{
                ump[nums[i]]--;
                if(ump[nums[i]] == 0){
                    cs -= nums[i];
                }
                i++;
            }
        }

        if(ans>=1e9) return -1;
        return ans;
    }
};