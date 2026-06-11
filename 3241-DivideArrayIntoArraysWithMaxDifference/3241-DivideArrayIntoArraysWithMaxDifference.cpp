// Last updated: 6/11/2026, 11:19:12 AM
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        int cnt = 0;
        for(int i=0; i<nums.size(); i++){
            cnt++;
            if(temp.size()>0 && (nums[i] - temp[0] > k)){
                ans.clear();
                return ans;
            } 
            temp.push_back(nums[i]);
            if(cnt == 3){
                ans.push_back(temp);
                temp.clear();
                cnt = 0;
            }
        }

        return ans;
    }
};