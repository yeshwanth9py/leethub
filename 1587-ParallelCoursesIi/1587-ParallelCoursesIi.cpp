// Last updated: 6/11/2026, 11:27:26 AM
class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        vector<int> prereq(n, 0);
        vector<int> dist((1<<n), 1e9);

        for(auto rel: relations){
            int a = rel[0];
            int b = rel[1];
            a--;
            b--;
            prereq[a] |= (1<<b);
        }

        queue<int> q; //mask
        q.push(0); //
        dist[0] = 0;
        while(!q.empty()){
            auto tn = q.front(); q.pop();
            int temp = 0;
            for(int i=0; i<n; i++){
                if(((tn&(1<<i)) == 0) && ((prereq[i]&tn) == prereq[i])){
                    temp = (temp | (1<<i));
                }
            }

            for(int sub = temp; sub>0; sub = ((sub-1)&temp)){
                if(__builtin_popcount(sub)<=k){
                    int nmask = (tn|sub);
                    if(dist[nmask] > dist[tn] + 1){
                        dist[nmask] = min(dist[tn] + 1, dist[nmask]);
                        if(nmask == (1<<n)-1) return dist[nmask];
                        q.push(nmask);
                    }
                }
            }
        }

        return -1;

    }
};