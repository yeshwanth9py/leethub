// Last updated: 6/11/2026, 11:24:51 AM
struct Unionfind{
    long long n;
    vector<long long> par;
    vector<long long> sz;
    Unionfind(long long n){
        this->n = n;
        par.resize(n, 1);
        sz.resize(n, 1);
        for(long long i=0; i<n; i++){
            par[i] = i;
        }
    }
    long long find(long long x){
        if(x == par[x]) return x;
        return par[x] = find(par[x]);
    }

    void merge(int x,int y){
        x = find(x);
        y = find(y);
        if(x == y) return;
        if(sz[y]>sz[x]) swap(x, y);
        sz[x] += sz[y];
        par[y] = x;
    }
    
};
class Solution {
public:
    vector<long long> spf;
    void sieveofera(){
        spf.resize(1e6, 1);
        for(long long i=2; i<1e6; i++){
            if(spf[i] == 1){
                for(long long j=i; j<1e6; j=j+i){
                    spf[j] = i;
                }
            }
        } 
    }

    vector<long long> get_primef(long long el){
        vector<long long> ans;
        while(el>1){
            long long sp = spf[el];
            long long cnt = 0;
            while(el%sp == 0){
                el = el/sp;
                cnt++;
            }
            ans.push_back(sp);
        }
        return ans;
    }
    
    bool gcdSort(vector<int>& nums) {
        sieveofera();
        Unionfind uf(1e6);
        long long n = nums.size();
        for(long long i=0; i<nums.size(); i++){
            long long el = nums[i];
            vector<long long> allpfacts = get_primef(el);
            // cout<<el<<":- ";
            for(long long e: allpfacts){
                // cout<<e<<" ";
                uf.merge(e, el);
            }
            cout<<endl;
        }
        vector<int> dnums = nums;
        sort(dnums.begin(), dnums.end());
        for(int i=0; i<n; i++){
            if(uf.find(dnums[i]) != uf.find(nums[i])) return 0;
        }
        return 1;
    }
};











