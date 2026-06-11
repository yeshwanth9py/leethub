// Last updated: 6/11/2026, 11:15:20 AM
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        stack<int> st;
        st.push(0);
        int op = 0;
        for(int i=0; i<n; i++){
            while(!st.empty() && st.top()>nums[i]){
                st.pop();
            }
            if(!st.empty() && st.top() == nums[i]){
                continue;
            }else{
                st.push(nums[i]);
                op++;
            }
        }

        return op;
    }
};