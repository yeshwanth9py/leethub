// Last updated: 6/11/2026, 11:29:44 AM
struct DSU{
    vector<int> par;
    vector<int> sz;
    DSU(int n){
        par.resize(n, 1);
        sz.resize(n, 1);
        for(int i=0; i<n; i++){
            par[i] = i;
        }
    }
    int find(int x){
        if(x == par[x]){
            return x;
        }
        return par[x] = find(par[x]);
    }

    void merge(int a, int b){
        int ra = find(a);
        int rb = find(b);
        if(ra == rb) return;
        if(ra>=rb){
            sz[rb]+=sz[ra];
            par[ra] = rb;
        }else{
            sz[ra] += sz[rb];
            par[rb] = ra;
        }
    }
};

class Solution {
public: 
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DSU uf(26);  
        for(int i=0; i<s1.length(); i++){
            uf.merge(s1[i]-'a', s2[i]-'a');
        }

        string temp = "";
        for(char ch: baseStr){
            int parind = uf.find(ch-'a');
            temp += static_cast<char>(parind+'a');
        }

        return temp;
    }
};