// Last updated: 6/11/2026, 11:36:58 AM
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        
        int ans = 0;

        auto find_hist_area = [&](vector<int> &temp){
            stack<int> st;
            int n = temp.size();
            vector<int> r_min(n, n);
            vector<int> l_min(n, -1);

            for(int i=0; i<n; i++){
                while(!st.empty() && temp[st.top()]>=temp[i]){
                    st.pop();
                }
                if(!st.empty()){
                    l_min[i] = st.top();
                }
                st.push(i);
            }
            while(!st.empty()) st.pop();

            for(int i=n-1; i>=0; i--){
                while(!st.empty() && temp[st.top()]>=temp[i]){
                    st.pop();
                }
                if(!st.empty()){
                    r_min[i] = st.top();
                }
                st.push(i);
            }

            int ans = 0;


            for(int i=0; i<n; i++){
                int len = r_min[i] - l_min[i]-1;
                int area = len*(temp[i]);
                // cout<<" "<<i<<": "<<r_min[i]<<" "<<l_min[i]<<", ";
                ans = max(ans, area);
            }

            return ans;

        };


        vector<int> temp(m, 0);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == '1'){
                    temp[j] += 1;
                }else{
                    temp[j] = 0;
                }
                // cout<<temp[j]<<" ";
            }
            int cura = find_hist_area(temp);
            // cout<<": "<<cura<<" "<<endl;
            ans = max(ans, cura);
        }

        return ans;


    }
};