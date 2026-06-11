// Last updated: 6/11/2026, 11:26:16 AM
class Solution {
public:
    int minimumTeachings(int ln, vector<vector<int>>& lang, vector<vector<int>>& frie) {
        unordered_set<int> unfrie;

        for(auto vec: frie){
            int u = vec[0];
            int v = vec[1];
            unordered_set<int> lku;
            for(int l: lang[u-1]){
                lku.insert(l);
            }
            bool happy = 0;
            for(int l: lang[v-1]){
                if(lku.find(l)!=lku.end()){
                    happy = 1;
                    break;
                }
            }
            if(happy == 0){
                unfrie.insert(u);
                unfrie.insert(v);
            }
        }

        unordered_map<int, int> ump;
        int maxl = 0;
        for(int p: unfrie){
            for(int l: lang[p-1]){
                ump[l]++;
                maxl = max(maxl, ump[l]);
            }
        }

        return unfrie.size()-maxl;

    }
};