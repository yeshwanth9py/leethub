// Last updated: 6/11/2026, 11:34:01 AM
class Solution {
public:
    string getHint(string secret, string guess) {
        int b = 0;
        int n = guess.length();
        unordered_map<char, int> avail;

        for(int i=0; i<n; i++){
            if(guess[i] == secret[i]){
                b++;
            }else{
                avail[secret[i]]++;
            }
        }

        int c = 0;
        for(int i=0; i<n; i++){
            if(guess[i]!=secret[i]){
                if(avail[guess[i]]>0){
                    c++;
                    avail[guess[i]]--;
                }
            }
        }

        return to_string(b)+"A"+to_string(c)+"B";

    }
};