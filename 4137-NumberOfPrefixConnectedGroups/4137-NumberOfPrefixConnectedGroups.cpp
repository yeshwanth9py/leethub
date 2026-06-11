// Last updated: 6/11/2026, 11:12:08 AM
class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        map<string, int> mp;
        // cout<<words.size()<<endl;
        for(string w: words){
            if(w.size()<k) continue;
            string sub = w.substr(0, k);
            mp[sub]++;
        }
        
        int ans = 0;
        for(auto el: mp){
            if(el.second>=2){
                ans++;
            }
        }
        return ans;
    }
};