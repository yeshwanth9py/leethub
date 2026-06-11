// Last updated: 6/11/2026, 11:31:30 AM
class Solution {
public:
    unordered_map<string, int> allow;
    map<pair<string, string>, int> mp;
    bool rec(int ind, string bot, string top){
        if(ind == bot.size()-1){
            if(ind == 1) return 1;
            if(mp.find({bot, top})!=mp.end()) return mp[{bot, top}];
            // bot = string(top);
            // ind = 0;
            // string ex = "";
            return mp[{bot, top}] = rec(0, top, "");
        }

        if(mp.find({bot, top})!=mp.end()) return mp[{bot, top}];

        bool ans = 0;
        for(int i=0; i<7; i++){
            char ch = 'A'+i;
            // cout<<ch<<" "<<endl;
            string tri = string(1, bot[ind]) + string(1, bot[ind+1])+ch;
            if(allow.find(tri)==allow.end()) continue;
            top.push_back(ch);
            ans |= rec(ind+1, bot, top);
            top.pop_back();
            if(ans) return mp[{bot, top}] = 1;
        }

        return mp[{bot, top}] = ans;
    }
    
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        
        for(string s: allowed){
            allow[s] = 1;
        }

        string ex = "";
        return rec(0, bottom, ex);

        return 1;
    }
};