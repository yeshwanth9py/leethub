// Last updated: 6/11/2026, 11:30:37 AM
class Solution {
public:
    int robotSim(vector<int>& com, vector<vector<int>>& obs) {
        // vector<char> dir = {'N', 'E', 'S', 'W'};
        unordered_map<int, vector<int>> umpx;
        unordered_map<int, vector<int>> umpy;

        for(auto el: obs){
            int x = el[0];
            int y = el[1];
            umpx[x].push_back(y);
            umpy[y].push_back(x);
        }
        for(auto el: umpx){
            int fv = el.first;
            sort(umpx[fv].begin(), umpx[fv].end());
        }

        for(auto el: umpy){
            int fv = el.first;
            sort(umpy[fv].begin(), umpy[fv].end());
        }

        int curx = 0;
        int cury = 0;
        int dir = 0;

        int ans = 0;

        for(int el: com){
            if(el == -1){
                dir = (dir+1)%4;
            }else if(el == -2){
                dir = (dir-1+4)%4;
            }else{
                if(dir == 0){
                    int desty = cury + el;
                    auto it = upper_bound(umpx[curx].begin(), umpx[curx].end(), cury);
                    if(it == umpx[curx].end() || *it>desty){
                        cury = desty;
                    }else{
                        cury = (*it)-1;
                    }
                    ans = max(ans, (cury*cury) + (curx*curx));
                }else if(dir == 2){
                    int desty = cury - el;
                    auto it = lower_bound(umpx[curx].begin(), umpx[curx].end(), cury);
                    if(it == umpx[curx].begin()){
                        cury = desty;
                    }else{
                        it--;
                        if(*it>=desty){
                            desty = (*it)+1;
                        }
                        cury = desty;
                    }
                    ans = max(ans, (cury*cury) + (curx*curx));
                }else if(dir == 1){
                    int destx = curx + el;
                    auto it = upper_bound(umpy[cury].begin(), umpy[cury].end(), curx);
                    if(it == umpy[cury].end() || *it>destx){
                        curx = destx;
                    }else{
                        curx = (*it)-1;
                    }
                    ans = max(ans, (cury*cury) + (curx*curx));
                }else{
                    int destx = curx - el;
                    auto it = lower_bound(umpy[cury].begin(), umpy[cury].end(), curx);
                    if(it == umpy[cury].begin()){
                        curx = destx;
                    }else{
                        it--;
                        if(*it>=destx){
                            destx = (*it)+1;
                        }
                        curx = destx;
                    }
                    ans = max(ans, (cury*cury) + (curx*curx));
                }
            }
        }

        return ans;
        

    }
};