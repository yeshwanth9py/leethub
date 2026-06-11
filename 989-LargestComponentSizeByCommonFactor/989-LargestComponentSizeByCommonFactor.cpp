// Last updated: 6/11/2026, 11:30:11 AM
struct Unionfind{
    vector<int> par;
    vector<int> sz;
    int maxsz;

    Unionfind(int n){
        par.resize(n, 0);
        sz.resize(n, 1);
        for(int i=0; i<n; i++){
            par[i] = i;
        }
        maxsz = 1;
    }

    int find(int x){
        if(par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    void merge(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return;
        if(sz[y]>=sz[x]) swap(x, y);
        sz[x] += sz[y];
        maxsz = max(maxsz, sz[x]);
        par[y] = x;
    }
};


class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> ump;

        for(int i=0; i<n; i++){
            int el = nums[i];
            int del = el;
            for(int j=2; j*j<=del; j++){
                if(del%j == 0){
                    while(del%j == 0){
                        del = del/j;
                    }
                    ump[j].push_back(i);
                }
            }
            if(del>1){
                ump[del].push_back(i);
            }
        }

        Unionfind uf(n);

        for(auto &el: ump){
            vector<int>& all = el.second;
            for(int j=0; j<all.size()-1; j++){
                uf.merge(all[j], all[j+1]);
            }
        }

        return uf.maxsz;


    }
};