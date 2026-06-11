// Last updated: 6/11/2026, 11:29:15 AM
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& nums) {
        map<pair<int,int>,int> ump;
        int cnt = 0;
        for(auto el: nums){
            int a =el[0];
            int b=el[1];

            if(a>b) swap(a,b);

            if(ump.find({a,b})!=ump.end()){
                 cnt += ump[{a,b}];
            } 
            ump[{a,b}]++;
            

        }
        return cnt; 
    }
};