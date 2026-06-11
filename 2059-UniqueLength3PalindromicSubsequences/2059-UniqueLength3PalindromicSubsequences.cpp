// Last updated: 6/11/2026, 11:25:08 AM
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        map<char, multiset<int>> ump;

        for(int i=0; i<n; i++){
            ump[s[i]].insert(i);
        }
        
        int ans = 0;
        vector<int> done(26, 0);
        int cnt = 0;
        for(int i=0; i<n; i++){
            char ch = s[i];
            if(done[ch-'a']) continue;
            done[ch-'a'] = 1;

            int r = *(ump[ch].rbegin());

            if(r<=i) continue;
            //try all chars from 0 to 25
            for(int j=0; j<26; j++){
                //char = j search btw i to r
                char chh = char('a'+j);
                auto it = ump[chh].upper_bound(i);
                if(it == ump[chh].end()) continue;
                int mid = *(it);
                if(mid<r){
                    cnt++;
                }
            }
        }

        return cnt;


    }
};