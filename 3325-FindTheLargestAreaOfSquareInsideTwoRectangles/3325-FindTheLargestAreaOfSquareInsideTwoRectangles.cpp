// Last updated: 6/11/2026, 11:18:51 AM
#define ll long long
class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bl, vector<vector<int>>& tr) {
        ll maxarea = 0;
        for(ll i=0; i<bl.size(); i++){ 
            for(ll j=i+1; j<tr.size(); j++){
                ll x1 = bl[i][0];
                ll y1 = bl[i][1];
                ll x2 = tr[i][0];
                ll y2 = tr[i][1];

                ll x11 = bl[j][0];
                ll y11 = bl[j][1];
                ll x22 = tr[j][0];
                ll y22 = tr[j][1];
                 
                if( (((x11>=x1 && x11<=x2) || (x22>=x1 && x22<=x2)) || (x1>=x11 && x1<=x22) || (x2>=x11 && x2<=x22)) &&
                    (((y11>=y1 && y11<=y2) || (y22>=y1 && y22<=y2)) || (y1>=y11 && y1<=y22) || (y2>=y11 && y2<=y22)) ){
                    ll len = abs(max(x1, x11) - min(x2, x22));
                    ll ht = abs(max(y1, y11)- min(y2, y22));
                    // cout<<len<<" "<<ht<<endl;
                    ll cura = min(len, ht)*min(len, ht);
                    maxarea = max(maxarea, cura);
                }
            }
        }

        return maxarea;

    }
};