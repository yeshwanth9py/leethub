// Last updated: 6/11/2026, 11:16:21 AM
class Solution {
public:
    vector<int> solveQueries(vector<int>& arr, vector<int>& que) {
        unordered_map<int, vector<int>> ump;
        int n = arr.size();
        for(int i=0; i<arr.size(); i++){
            ump[arr[i]].push_back(i);
        }
        // for(auto el: ump){
        //     cout<<el.first<<":- ";
        //     for(int j: el.second){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        vector<int> ans;
        for(int idx: que){
            int el = arr[idx];
            int indx = lower_bound(ump[el].begin(), ump[el].end(), idx) - ump[el].begin();
            int sz = ump[el].size();
            if(sz == 1) {
                ans.push_back(-1);
                continue;
            }
            // cout<<el<<" "<<indx<<", ";
            int pindx = (indx - 1 + sz)%sz;
            int nindx = (indx+1)%sz;

            int cur = min(abs(ump[el][indx] - ump[el][pindx]), abs(ump[el][indx] - ump[el][nindx]));
            if(ump[el][pindx]>ump[el][indx]){
                cur = min(cur, ump[el][indx]+(n-ump[el][pindx]));
            }
            if(ump[el][nindx]<ump[el][indx]){
                cur = min(cur, ump[el][nindx]+(n-ump[el][indx]));
            }

            ans.push_back(cur);
            // cout<<abs(ump[el][indx] - ump[el][pindx])<<" "<<abs(ump[el][indx] - ump[el][nindx])<<endl;
        }

        return ans;
    }
};