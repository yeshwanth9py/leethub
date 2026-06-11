// Last updated: 6/11/2026, 11:10:33 AM
class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        stack<long long> st;
        long long n = nums.size();
        for(long long i=0; i<n; i++){
            long long el = nums[i];
            while(st.size()>0 && st.top() == el){
                st.pop();
                el = 2*el;
            }
            st.push(el);
        }
        vector<long long> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};