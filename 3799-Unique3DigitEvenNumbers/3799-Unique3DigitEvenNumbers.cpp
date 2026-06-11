// Last updated: 6/11/2026, 11:15:42 AM
class Solution {
public:
    set<vector<int>> us;
    void rec(int ind, vector<int> &cur, vector<int> &digits, vector<int> &vis){
        if(ind >= 3){
            us.insert(cur);
            return;
        }
        
        for(int i=0; i<digits.size(); i++){
            if(vis[i] == 0){
                if(ind == 2 && digits[i]==0) continue;
                cur.push_back(digits[i]);
                vis[i] = 1;
                rec(ind+1, cur, digits, vis);
                vis[i] = 0;
                cur.pop_back();
            }
        }  
    }
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<int> cur;
        vector<int> vis(n, 0);
        for(int i=0; i<n; i++){
            if(digits[i]%2 == 0){
                cur.push_back(digits[i]);
                vis[i] = 1;
                rec(1, cur, digits, vis);
                vis[i] = 0;
                cur.pop_back();
            }
        }

        // for(auto el: us){
        //     for(int e: el){
        //         cout<<e<<" ";
        //     }
        //     cout<<endl;
        // }
        
        return us.size();
    }
};