// Last updated: 6/11/2026, 11:31:43 AM
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        for(int i=0; i<n; i++){
            int cur = arr[i];
            bool add = 1;
            while(!st.empty() && st.top()>0 && cur<0){
                int rem = cur+st.top();
                if(rem<0){
                    st.pop();
                }else if(rem == 0){
                    add = 0;
                    st.pop();
                    break;
                }else{
                    add = 0;
                    break;
                }
            }
            if(add) st.push(arr[i]);
        }

        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;


    }
};