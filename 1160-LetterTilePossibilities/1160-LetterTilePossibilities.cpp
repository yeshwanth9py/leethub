// Last updated: 6/11/2026, 11:29:28 AM
class Solution {
public:
    void rec(int ind, set<string> &s, string tiles, string temp, vector<int> &vis){
        if(ind >= tiles.length()){
            s.insert(temp);
            return;
        }

        for(int i=0; i<tiles.length(); i++){
            if(vis[i] == 0){
                vis[i] = 1;
                rec(ind+1, s, tiles, temp+tiles[i], vis);
                vis[i] = 0;
            }
        }
        rec(ind+1, s, tiles, temp, vis);
    }
    int numTilePossibilities(string tiles) {
        set<string> s;
        vector<int> vis(tiles.length(), 0);
        rec(0, s, tiles, "", vis);
        return s.size()-1;
    }
};