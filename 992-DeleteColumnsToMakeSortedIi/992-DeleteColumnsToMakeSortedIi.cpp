// Last updated: 6/11/2026, 11:30:10 AM
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        set<int> st;

        int ans = 0;
        for(int i=0; i<strs[0].size(); i++){
            st.insert(i);
        }
        ans = strs[0].size();

        int amo = 1;
        while(amo && st.size()>0){
            string prev = strs[0];
            amo = 0;
            for(int i=1; i<strs.size(); i++){
                set<int> newst = st;
                prev = strs[i-1];
                string cur = strs[i];
                // cout<<endl;
                // cout<<prev<<" "<<cur<<" ";
                bool g = 0;
                for(int idx: st){
                    // cout<<idx<<", ";
                    if(prev[idx] < cur[idx]){
                        g = 1;
                        break;
                    }else if(prev[idx] == cur[idx]){
                        continue;
                    }else{
                        amo = 1;
                        newst.erase(idx);
                    }
                }
                st = newst;
            }
        }
        

        return ans-st.size();

    }
};