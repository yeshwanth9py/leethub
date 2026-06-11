// Last updated: 6/11/2026, 11:32:51 AM
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> nums2 = nums;
        // nums2.insert(nums2.end(), nums.begin(), nums.end());
        int nge[nums2.size()];
        int n = nums2.size();

        nge[nums2.size()-1] = -1;
        stack<int> st;
        st.push(nums2[nums2.size()-1]);
        for(int i=2*nums2.size()-2; i>=0; i--){
            while(!st.empty() && st.top()<= nums2[i%n]){
                st.pop();
            }
            if(!st.empty()){
                nge[i%n] = st.top();
            }else{
                nge[i%n] = -1;
            }
            st.push(nums2[i%n]);
        }

        vector<int> ans;

        for(int i=0; i<nums.size(); i++){
            ans.push_back(nge[i]);
        }
        return ans;
    }
};