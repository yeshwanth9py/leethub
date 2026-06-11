// Last updated: 6/11/2026, 11:14:11 AM
class Solution {
public:
    int minOperations(string s, int k) {
        queue<vector<int>> q;
        int noz = 0;
        int noo = 0;
        for(char ch: s){
            if(ch == '0'){
                noz++;
            }else{
                noo++;
            }
        }

        int n = s.size();
        if(noz == 0) return 0;

        vector<int> vis(n+2, 0);
        vis[noz] = 1;

        q.push({noz, 0});

        set<int> oddz;
        set<int> evez;

        for(int i=0; i<=n; i++){
            if(i%2 == 0){
                evez.insert(i);
            }else{
                oddz.insert(i);
            }
        }
        
        int ans = 0;
        while(!q.empty()){
            auto tel = q.front(); q.pop();
            int noz = tel[0];
            int nop = tel[1];
            
            if(noz == 0){
                return nop;
            }

            //k-f<=n-z
            //f>=k+z-n
            int minf = max(0, k+noz-n);
            int maxf = min(noz, k);

            // for(int op = minf; op<=maxf; op++){ 
            //     //noz-f+(k-f)
            //     int nnoz = noz+k-2*op;
            //     if(vis[nnoz]==0){
            //         vis[nnoz] = 1;
            //         q.push({nnoz, nop+1});
            //     }
            // }

            int maxoz = noz+k-2*minf;
            int minoz = noz+k-2*maxf;

            auto &currs = (minoz%2)?oddz:evez;

            auto it = currs.lower_bound(minoz);
            if(it == currs.end()){
                continue;
            }

            while(it!=currs.end() && *it<=maxoz){
                int nnoz = *it;
                vis[nnoz] = 1;
                it = currs.erase(it);
                q.push({nnoz, nop+1});
            }
        }

        return -1;
    }
};