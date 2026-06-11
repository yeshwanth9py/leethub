// Last updated: 6/11/2026, 11:11:26 AM

#define ll long long
class Solution {
public:
    long long minimumCost(string s, string t, int fc, int sc, int cc) {
        ll ty0 = 0;
        ll ty1 = 0;

        for(ll i=0; i<s.size(); i++){
            if(s[i] == t[i]){
                continue;
            }else if(s[i] == '0'){
                ty0++;
            }else{
                ty1++;
            }
        }

        ll c1 = (ty0+ty1)*fc;

        if(ty0 == ty1){
            //000111
            c1 = min(c1, ty0*sc);
        }else{
            //000111 11
            ll mn = min(ty0, ty1);
            ll c2 = mn*sc;
            c2 += ((max(ty0, ty1)-mn)/2)*cc + ((max(ty0, ty1)-mn)/2)*sc + (((max(ty0, ty1)-mn)%2 == 1)?fc:0);
            ll c3 = mn*sc + ((max(ty0, ty1)-mn))*fc;
            c1 = min({c1, c2, c3});
        }

        return c1;

    }
};