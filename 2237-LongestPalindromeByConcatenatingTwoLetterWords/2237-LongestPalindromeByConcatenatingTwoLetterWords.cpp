// Last updated: 6/11/2026, 11:23:52 AM
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> ump;
        for(int i=0; i<words.size(); i++){
            ump[words[i]]++;
        }

        int cnt = 0;
        bool hasCenter = false;

        for(auto &el: ump){
            if(el.second == 0) continue;
            string curw = el.first;
            string revw = curw;
            reverse(revw.begin(), revw.end());
            if(ump.find(revw)==ump.end()){
                continue;
            }
           if(curw==revw){
               int pairs = ump[curw] / 2;
               cnt += pairs * 2;
               if (ump[curw] % 2 == 1) hasCenter = true;
               ump[curw] = 0;
               continue;   
           }

            // non-palindromic match
            cnt += 2*min(ump[curw], ump[revw]);
            ump[curw] = ump[revw] = 0;
        }

        return 2 * cnt + (hasCenter ? 2 : 0);
    }
};
