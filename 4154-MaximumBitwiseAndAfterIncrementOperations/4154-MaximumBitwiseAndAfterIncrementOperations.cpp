// Last updated: 6/11/2026, 11:11:27 AM

#define ll long long
class Solution {
public:
    int maximumAND(vector<int>& nums, int k, int m) {
        ll ans = 0;
        vector<int> temp = nums;
        
        ll left = k;
        for(ll i=30; i>=0; i--){
            ll cnt = 0;
            vector<pair<ll, ll>> stb;
            vector<int> ntemp;
            for(ll j=0; j<temp.size(); j++){
                if((temp[j]&(1LL<<i)) != 0){
                    ntemp.push_back(temp[j]);
                }else{
                    ll need = (1LL<<i) - (temp[j]&((1LL<<i)-1));
                    stb.push_back({need, temp[j]});
                }
            }
        
            sort(stb.rbegin(), stb.rend());
            while(ntemp.size()<m && stb.size()>0){
                auto [opn, nom] = stb.back(); stb.pop_back();
                cnt += opn;
                nom += opn;
                ntemp.push_back(nom);
            }

            if(ntemp.size()>=m && cnt<=left){
                left -= cnt;
                ans |= (1LL<<i);
                temp = ntemp;
                // for(int el: temp) cout<<el<<", ";
                // cout<<endl;
            }else{
                continue;
            }
        }
        
        return ans;
    }
};