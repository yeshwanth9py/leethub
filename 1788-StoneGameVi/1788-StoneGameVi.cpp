// Last updated: 6/11/2026, 11:26:35 AM
class Solution {
public:
    int stoneGameVI(vector<int>& av, vector<int>& bv) {
        vector<pair<int, int>> vec;
        int n = av.size();
        for(int i=0; i<n; i++){
            vec.push_back({av[i], bv[i]});
        }
        sort(vec.begin(), vec.end(), [](pair<int, int> &a, pair<int, int> &b){
            return a.first+a.second > b.first+b.second;
        });

        int p1 = 0;
        int p2 = 0;
        bool flag = 1;
        for(int i=0; i<n; i++){
            if(flag){
                p1 += vec[i].first;
                flag = 0;
            }else{
                p2 += vec[i].second;
                flag = 1;
            }
        }

        if(p1>p2){
            return 1;
        }else if(p1 == p2){
            return 0;
        }else{
            return -1;
        }
    }
};