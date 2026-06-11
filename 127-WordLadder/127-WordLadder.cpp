// Last updated: 6/11/2026, 11:36:11 AM
class Solution {
public:
    unordered_map<string, int> ump;
    unordered_map<int, string> umpsti;
    int tot;
    int ladderLength(string bw, string ew, vector<string>& wl) {
        ump[bw] = 1;
        // ump[ew] = 1;
        for(auto s: wl){
            ump[s] = 1;
        }

        int no = 1;
        for(auto &el: ump){
            ump[el.first] = no;
            umpsti[no] = el.first;
            no++;
        }

        tot = no;
        queue<int> q;
        vector<int> dist(tot, 1e9);

        q.push(ump[bw]);
        dist[ump[bw]] = 0;

        while(!q.empty()){
            auto tel = q.front(); q.pop();
            string giv = umpsti[tel];
            for(int i=0; i<giv.size(); i++){
                string temp = giv;
                for(int j=0; j<26; j++){
                    temp[i] = char(j+'a');
                    // cout<<temp<<" ";
                    if(ump.find(temp) == ump.end()) continue;
                    int neino = ump[temp];
                    if(neino>0 && dist[neino]>dist[tel]+1){
                        dist[neino] = dist[tel]+1;
                        q.push(neino);
                    }
                }
            }
        }

        if(ump.find(ew) == ump.end()) return 0;

        return ((dist[ump[ew]]>=1e8)?0:dist[ump[ew]]+1);
    }
};





