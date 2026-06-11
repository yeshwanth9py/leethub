// Last updated: 6/11/2026, 11:20:35 AM
class Solution {
public:
    unordered_map<int, int> ump;//node-mask
    vector<vector<int>> adjl;
    int n;
    string s;
    void dfs(int node, int pp, int mask){
        int nmask = mask;
        if(node != 0){
            int ch = s[node]-'a';
            nmask ^= (1LL<<ch);
        }
        ump[node] = nmask;
        
        for(int nei: adjl[node]){
            if(nei != pp){
                dfs(nei, node, nmask);
            }
        }
    }
    
    long long countPalindromePaths(vector<int>& par, string ss) {
        n = par.size();
        s = ss;
        adjl.resize(n, vector<int>());
        for(int i=0; i<n; i++){
            int p = par[i];
            if(p == -1) continue;
            adjl[p].push_back(i);
            adjl[i].push_back(p);
        }

        dfs(0, -1, 0);

        auto ispalindmask = [&](int mask){
            if(mask == 0) return 1;
            for(int i=0; i<26; i++){
                if(mask == (1LL<<i)){
                    return 1;
                }
            }
            return 0;
        };

        unordered_map<int, int> prev;

        long long ans = 0;
        for(int i=1; i<n; i++){
            int curm = ump[i];
            if(ispalindmask(curm)){
                ans++;
            }

            if(prev.find(curm) != prev.end()){
                ans += prev[curm];
            }

            for(int j=0; j<26; j++){
                int nmask = (curm ^ (1LL<<j));
                if(prev.find(nmask) != prev.end()){
                    ans += prev[nmask];
                }
            }
            
            prev[curm]++;
        }

        return ans; 
        
    }
};