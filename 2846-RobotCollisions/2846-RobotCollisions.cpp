// Last updated: 6/11/2026, 11:20:46 AM
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& h, string dir) {
        vector<vector<int>> vec;
        for(int i=0; i<pos.size(); i++){
            vec.push_back({pos[i], h[i], ((dir[i] == 'R')?1:-1), i});
        }
        sort(vec.begin(), vec.end());

        stack<vector<int>> st;

        for(int i=0; i<pos.size(); i++){
            int cur = vec[i][1];
            int curdir = vec[i][2];
            int actp = vec[i][3];

            bool surv = 1;
            while(!st.empty() && st.top()[0]>0 && curdir==-1){
                auto prev = st.top(); st.pop();
                if(prev[1]>cur){
                    prev[1] = prev[1]-1;
                    st.push(prev);
                    surv = 0;
                    break;
                }else if(prev[1] == cur){
                    surv = 0;
                    break;
                }else{
                    cur -= 1;
                }
            }
            if(surv){
                st.push({curdir, cur, actp});
            }
        }

        vector<pair<int, int>> ans;
        while(!st.empty()){
            ans.push_back({st.top()[2], st.top()[1]});
            st.pop();
        }

        // reverse(ans.begin(), ans.end());

        sort(ans.begin(), ans.end());

        vector<int> asans;
        for(auto el: ans){
            asans.push_back(el.second);
        }

        return asans;
    }
};