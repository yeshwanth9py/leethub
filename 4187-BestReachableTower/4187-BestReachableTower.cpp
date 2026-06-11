// Last updated: 6/11/2026, 11:10:53 AM
class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& t, vector<int>& cr, int rd) {
        int ansx = -1;
        int ansy = -1;
        int ansq = 0;
        
        bool upd = 0;
        
        int cx = cr[0];
        int cy = cr[1];
        for(auto el: t){
            int x = el[0];
            int y = el[1];
            int val = el[2];
            if(abs(x-cx) + abs(y-cy)<=rd){
                if(upd == 0){
                    ansx = x;
                    ansy = y;
                    ansq = val;
                }else{
                    if(ansq < val){
                        ansx = x;
                        ansy = y;
                        ansq = val;
                    }else if(ansq == val){
                        if(ansx>x || (ansx==x && ansy>y)){
                            ansx = x;
                            ansy = y;
                            ansq = val;
                        }
                    }
                }
                upd = 1;
            }
        }

        return {ansx, ansy};
    }
};