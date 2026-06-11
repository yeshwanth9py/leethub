// Last updated: 6/11/2026, 11:26:13 AM


unordered_map<int, vector<int>> ump;

struct Unionfind{
    vector<int> par;
    vector<int> sz;
    int n;
    Unionfind(int n){
        par.resize(n, 1);
        this->n = n;
        sz.resize(n, 1);
        for(int i=0; i<n; i++) par[i] = i;
    }

    int find(int x){
        if(x == par[x]) return x;
        return par[x] = find(par[x]);
    }

    void merge(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b) return;
        if(sz[b]>=sz[a]) swap(a, b);
        sz[a] += sz[b];
        par[b] = a;
    }

    void process(){
        for(int i=0; i<n; i++){
            ump[find(i)].push_back(i);
        }
    }
};


class Solution {
public:
    int minimumHammingDistance(vector<int>& src, vector<int>& tgt, vector<vector<int>>& sw) {
        int n = src.size();
        ump.clear();
        Unionfind uf(n);

        for(auto el: sw){
            int a = el[0];
            int b = el[1];
            uf.merge(a, b);
        }

        uf.process();
        int ans = 0;

        for(auto el: ump){
            unordered_map<int, int> temp;

            for(int ind: el.second){
                temp[src[ind]]++;
            }

            for(int ind: el.second){
                if(temp[tgt[ind]] > 0){
                    temp[tgt[ind]]--;
                }else{
                    ans++;
                }
            }
        }

        return ans;


    }
};



