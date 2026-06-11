// Last updated: 6/11/2026, 11:15:28 AM
class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& arr) {
        unordered_map<int, pair<int, int>> umpxy;
        unordered_map<int, pair<int, int>> umpyx;
        
        for(auto vec: arr){
            int x = vec[0];
            int y = vec[1];

            if(umpxy.find(x)==umpxy.end()){
                umpxy[x] = {y, y};
            }else{
                umpxy[x].first = max(umpxy[x].first, y);
                umpxy[x].second = min(umpxy[x].second, y);
            }

            if(umpyx.find(y)==umpyx.end()){
                umpyx[y] = {x, x};
            }else{
                umpyx[y].first = max(umpyx[y].first, x);
                umpyx[y].second = min(umpyx[y].second, x);
            }
        }

        int ans = 0;
        for(auto vec: arr){
            int x = vec[0];
            int y = vec[1];

            if(umpxy[x].first>y && umpxy[x].second<y && umpyx[y].first>x && umpyx[y].second<x){
                ans++;
            }
        }
        return ans;
    }   
};