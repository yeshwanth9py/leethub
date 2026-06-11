// Last updated: 6/11/2026, 11:14:42 AM
class Solution {
public:
    static vector<int> spf;
    static void pre(int mx){
        if(spf.size() != 0) return;
        spf.resize(mx+1, 0);
        for(int i=1; i<=mx; i++){
            spf[i] = i;
        }
        for(int i=2; i*i<=mx; i++){
            if(spf[i] == i){
                for(int j=i*i; j<=mx; j=j+i){
                    if(spf[j] > i){
                        spf[j] = i;
                    }
                }
            }
        }
    }
    int n;
    unordered_map<int, vector<int>> ump;
    vector<vector<int>> adjl;

    Solution(){
        pre(1e6+1);
    }

    bool isprim(int el){
        if(el<=1) return 0;
        return spf[el] == el;
    }

    vector<int> getprimes(int el){
        vector<int> ans;
        while(el>1){
            int cspf = spf[el];
            while(el%cspf == 0){
                el = el/cspf;
            }
            ans.push_back(cspf);
        }

        return ans;
    }
    
    int minJumps(vector<int>& nums) {
        n = nums.size();
        adjl.resize(n, vector<int>());

        // int mxx = nums[0];
        // for(int e: nums){
        //     mxx = max(mxx, e);
        // }
        // // pre(mxx);

        for(int i=0; i<n; i++){
            if(isprim(nums[i])){
                ump[nums[i]].push_back(i);
            }else{
                vector<int> allpr = getprimes(nums[i]);
                for(int el: allpr){
                    ump[el].push_back(i);
                }
            }
        }

        vector<int> dist(n, 1e9);
        dist[0] = 0;
        queue<int> q;
        q.push(0);

        while(!q.empty()){
            auto tel = q.front(); q.pop();
            
            if(tel-1>=0 && dist[tel-1]>dist[tel]+1){
                dist[tel-1] = dist[tel]+1;
                q.push(tel-1);
            }

            if(tel+1<n && dist[tel+1]>dist[tel]+1){
                dist[tel+1] = dist[tel]+1;
                q.push(tel+1);
            }

            int el = nums[tel];
            if(isprim(el)){
                for(int nei: ump[el]){
                    if(dist[nei]>dist[tel]+1){
                        dist[nei] = dist[tel]+1;
                        q.push(nei); 
                    }
                }
                ump.erase(el);
            }
        }

        return dist[n-1];
    }
};

vector<int> Solution::spf;