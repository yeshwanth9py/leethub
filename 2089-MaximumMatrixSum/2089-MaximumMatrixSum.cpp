// Last updated: 6/11/2026, 11:25:04 AM

#define ll long long

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& mat) {
        ll cnt = 0;
        ll n = mat.size();
        vector<ll> sm;
        ll bea = 0;
        for(ll i=0; i<n; i++){
            for(ll j=0; j<n; j++){
                if(mat[i][j]<0){
                    cnt++;
                }
                sm.push_back(abs(mat[i][j]));
            }
        }

        if(cnt%2 == 0){
            cnt = 0;
        }else{
            cnt = 1;
            if(bea>0){
                cnt = 0;
            }
        }

        sort(sm.rbegin(), sm.rend());
        // reverse(sm.begin(), sm.end());

        for(ll el: sm) cout<<el<<" ";
        cout<<endl;


        cnt = (n*n)-cnt;  //+ve elems
        ll ans = 0;

        for(ll i=0; i<cnt; i++){
            ans += sm[i];
            // cout<<"+"<<sm[i];
        }

        for(ll i=cnt; i<n*n; i++){
            ans -= sm[i];
            // cout<<sm[i]<<", ";
        }

        return ans;
    }
};