// Last updated: 6/11/2026, 11:25:39 AM
class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
         vector<pair<int, pair<int, int>>> sweep;

         for(auto vec: intervals){
            int s = vec[0];
            int e = vec[1];
            sweep.push_back({s, {-1, e-s+1}});
            sweep.push_back({e, {queries.size()+1, e-s+1}});
         }

         for(int i=0; i<queries.size(); i++){
            int q = queries[i];
            sweep.push_back({q, {i, i}});
         }

         sort(sweep.begin(), sweep.end());

         int i=0;
         multiset<int> ms;
        //  ms.insert(0);
        vector<int> ans(queries.size(), 0);
         while(i<sweep.size()){
            int len = sweep[i].second.second;
            int sq = sweep[i].second.first;
            if(sq == -1){
                ms.insert(len);
            }else if(sq == queries.size()+1){
                ms.erase(ms.find(len));
            }else{
                ans[sq] = ((ms.size()>0)?*ms.begin():-1);
            }
            i++;
         }

         return ans;



    }
};