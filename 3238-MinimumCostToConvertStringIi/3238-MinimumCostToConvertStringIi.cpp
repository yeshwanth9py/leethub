// Last updated: 6/11/2026, 11:19:15 AM

#define ll long long
class Solution {
public:
    unordered_map<string, ll> ump;
    vector<vector<ll>> mat;
    ll n;
    string src;
    string tar;
    ll dp[1111];
    vector<int> validlens;
    ll getcost(string &sub, string &sub2){
        if(sub == sub2){
            return 0;
        }
        if(ump.find(sub) == ump.end() || ump.find(sub2) == ump.end()) return 1e15;
        ll id1 = ump[sub];
        ll id2 = ump[sub2];
        return mat[id1][id2];
    }

    ll rec(ll id){
        if(id >= n){
            return 0;
        }

        if(dp[id]!=-1) return dp[id];
        ll cost = 1e15;
        if(src[id] == tar[id]){
            cost = min(cost, rec(id+1));
        }

        for(int l: validlens){
            string sub = src.substr(id, l);
            string sub2 = tar.substr(id, l);
            ll cossst = getcost(sub, sub2);
            if(cossst>=1e15) continue;
            ll cossst2 = rec(id+l);
            if(cossst2>=1e15) continue;
            cost = min(cost, cossst+cossst2);
        }

        return dp[id] = cost;
    }

    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        n = source.size();
        this->src = source;
        this->tar = target;
        for(string s: original){
            ump[s] = 1;
            validlens.push_back(s.size());
        }

        memset(dp, -1, sizeof(dp));
        // memset(dp2, -1, sizeof(dp2));

        for(string s: changed){
            ump[s] = 1;
            validlens.push_back(s.size());
        }

        sort(validlens.begin(), validlens.end());
        validlens.erase(unique(validlens.begin(), validlens.end()), validlens.end());

        ll id = 1;
        for(auto el: ump){
            ump[el.first] = id;
            id++;
        }

        ll m = id+1;
        mat.resize(m, vector<ll>(m, 1e15));
        for(ll i=0; i<m; i++) mat[i][i] = 0;

        for(ll i=0; i<original.size(); i++){
            ll id1 = ump[original[i]];
            ll id2 = ump[changed[i]];
            ll c = cost[i];
            mat[id1][id2] = min(mat[id1][id2], c);
        }

        for(ll k=1; k<=id; k++){
            for(ll i=1; i<=id; i++){
                for(ll j=1; j<=id; j++){
                    mat[i][j] = min(mat[i][j], mat[i][k]+mat[k][j]);
                }
            }
        }

        // for(ll i=1; i<=id; i++){
        //     for(ll j=1; j<=id; j++){
        //         cout<<mat[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        ll ans = rec(0);
        if(ans>=1e15) return -1;
        return ans;

    }
};