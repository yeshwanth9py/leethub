// Last updated: 6/11/2026, 11:32:14 AM
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int, int>> all;

        int ty = 1;
        for(auto vec: nums){
            for(int el: vec){
                all.push_back({el, ty});
            }
            ty++;
        }

        sort(all.begin(), all.end());
        int n = all.size();

        unordered_map<int, int> ump;
        int curd = 0;
        int allty = nums.size();

        int i=0;
        int j=-1;
        int l = -1;
        int r = -1;
        int ans = 1e9;

        while(i<n){
            while(j+1<n && curd<allty){
                j++;
                int cty = all[j].second;
                ump[cty]++;
                if(ump[cty] == 1){
                    curd++;
                }
            }
            // if()
            // cout<<all[i].first<<" "<<all[j].first<<endl;

            if(curd>=allty){
                int st = all[i].first;
                int en = all[j].first;
                if(en-st+1<ans){
                    ans = en-st+1;
                    l = st;
                    r = en;
                }
            }

            if(i>j){
                i++;
                j=i-1;
            }else{
                int pty = all[i].second;
                ump[pty]--;
                if(ump[pty] == 0){
                    curd--;
                }
                i++;
            }
        }


        return {l, r};
    }
};