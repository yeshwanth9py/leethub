// Last updated: 6/11/2026, 11:32:09 AM
class Solution {
public:
    string predictPartyVictory(string s) {
        queue<char> q;
        for(int i=0; i<s.length(); i++){
            q.push(s[i]);
        }

        while(q.size()>1){
            char tel = q.front();
            q.pop();
            if(tel == 'R'){
                int cnt = 1;
                int rem = cnt;
                while(!q.empty() && rem>0){
                    int nel = q.front(); q.pop();
                    if(nel == 'R'){
                        cnt++;
                        rem++;
                    }else{
                        rem--;
                    }
                }
                if(q.empty()){
                    return "Radiant";
                }
                while(cnt--){
                    q.push('R');
                }
            }else{
                int cnt = 1;
                int rem = 1;
                while(!q.empty() && rem>0){
                    int nel = q.front(); q.pop();
                    if(nel == 'D'){
                        cnt++;
                        rem++;
                    }
                    else{
                        rem--;
                    }
                }
                if(q.empty()){
                    return "Dire";
                }
                while(cnt--){
                    q.push('D');
                }
            }
        }

        if(q.front()=='R'){
            return "Radiant";
        }else{
            return "Dire";
        }
    }
};