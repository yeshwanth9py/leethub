// Last updated: 6/11/2026, 11:34:39 AM
struct mycomp{
    bool operator()(vector<int> &a, vector<int> &b){
        if(a[0]!=b[0]){
            return a[0]<b[0];
        }else if(a[1]!=b[1]){
            return a[1]<a[2];
        }else{
            if(a[1] == 1){
                return a[2]>b[2];
            }else{
                return a[2]<b[2];
            }
        }
    }
};


class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& arr) {
        vector<vector<int>> ans;
        multiset<int> ms;

        vector<vector<int>> sweep;  //to store all the critical points

        for(auto el: arr){
            int sp = el[0];
            int ep = el[1];
            int ht = el[2];
            sweep.push_back({sp, 1, ht});
            sweep.push_back({ep, 2, ht});
        }

        sort(sweep.begin(), sweep.end(), mycomp());

        //move the sweep line through all the critical points
        for(auto el: sweep){
            int xp = el[0];
            int q = el[1];
            int ht = el[2];
            if(q == 1){
                int oldmxht = (ms.empty()?0:*(ms.rbegin()));
                ms.insert(ht);
                int newmxht = (ms.empty()?0:*(ms.rbegin()));
                if(newmxht != oldmxht){
                    ans.push_back({xp, newmxht});
                }
            }else{
                int oldmxt = (ms.empty()?0:*(ms.rbegin()));
                ms.erase(ms.find(ht));
                int newmxht = (ms.empty()?0:*(ms.rbegin()));
                if(newmxht != oldmxt){
                    ans.push_back({xp, newmxht});
                }
            }
        }

        return ans;
    }
};