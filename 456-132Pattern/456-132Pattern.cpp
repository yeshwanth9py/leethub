// Last updated: 6/11/2026, 11:33:03 AM
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int minel = nums[0];
        stack<pair<int, int>> st;
        for(int i=1; i<nums.size(); i++){
            while(!st.empty() && st.top().first<=nums[i]){
                st.pop();
            }

            if(!st.empty() && st.top().first>nums[i]){
                if(st.top().second<nums[i]){
                    return true;
                }
            }

            st.push({nums[i], minel});
            minel = min(minel, nums[i]);
        }

        return false;
    }
};