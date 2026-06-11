// Last updated: 6/11/2026, 11:23:06 AM
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<pair<int, int>> sweep;
        vector<int> ans(people.size(), 0);
        for(auto ve: flowers){
            int s = ve[0];
            int e = ve[1];
            sweep.push_back({s, -1});
            sweep.push_back({e, people.size()+1});
        }

        for(int i=0; i<people.size(); i++){
            int p = people[i];
            sweep.push_back({p, i});
        }

        sort(sweep.begin(), sweep.end());   
        int i=0;
        int cnt = 0;
        while(i<sweep.size()){
            if(sweep[i].second==people.size()+1){
                cnt--;
            }else if(sweep[i].second == -1){
                cnt++;
            }else{
                ans[sweep[i].second] = cnt;
            }
            i++;
        }

        return ans;
    }
};