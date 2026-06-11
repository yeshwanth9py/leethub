// Last updated: 6/11/2026, 11:32:55 AM
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> um;
        for(int i=0; i<nums2.size(); i++){
            um[nums2[i]] = i;
        }

        int nge[nums2.size()];
        nge[nums2.size()-1] = -1;

        stack<int> st;
        st.push(nums2[nums2.size()-1]);
        for(int i=nums2.size()-2; i>=0; i--){
            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }
            if(!st.empty()){
                nge[i] = st.top();
            }else{
                nge[i] = -1;
            }
            st.push(nums2[i]);
        }
        for(auto el: nge){
            cout<<el<<" ";
        }
        cout<<endl;

        vector<int> ans;
        for(int i=0; i<nums1.size(); i++){
            ans.push_back(nge[um[nums1[i]]]);
        }

        return ans;

    }
};