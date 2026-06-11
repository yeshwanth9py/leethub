// Last updated: 6/11/2026, 11:31:32 AM
class Solution {
public:
    unordered_map<string, int> banned;
    int openLock(vector<string>& deadends, string target) {
        vector<int> dist(10000, 1e9);
        for(string &s: deadends){
            banned[s] = 1;
        }

        if(banned["0000"] == 1) return -1;
        if(banned[target] == 1) return -1;
        dist[0] = 0;

        queue<string> q;
        q.push("0000");
        while(!q.empty()){
            string el = q.front(); q.pop();
            for(int d=0; d<4; d++){
                string s = el;
                int ch = (s[d]-'0');
                int nch;
                if(ch+1>9){
                    nch = 0;
                }else{
                    nch = ch+1;
                }

                s[d] = '0'+nch; 
                if(banned[s] != 1 && banned[el] != 1){
                    // adjl[stoi(s)].push_back(stoi(el));
                    // adjl[stoi(el)].push_back(stoi(s));
                    int num1 = stoi(el);
                    int num2 = stoi(s);
                    if(dist[num2]>dist[num1]+1){
                        dist[num2] = dist[num1]+1;
                        q.push(s);
                    }
                }

                s = el;
                if(ch-1<0){
                    nch = 9;
                }else{
                    nch = ch-1;
                }
                s[d] = '0'+nch;
                if(banned[s] != 1  && banned[el]!=1){
                    // adjl[stoi(s)].push_back(stoi(el));
                    // adjl[stoi(el)].push_back(stoi(s));
                    int num1 = stoi(el);
                    int num2 = stoi(s);
                    if(dist[num2]>dist[num1]+1){
                        dist[num2] = dist[num1]+1;
                        q.push(s);
                    }
                }
            }
        }

        return ((dist[stoi(target)]<1e9)?dist[stoi(target)]:-1);


    }
};