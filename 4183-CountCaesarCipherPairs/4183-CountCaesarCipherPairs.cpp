// Last updated: 6/11/2026, 11:10:57 AM
class Solution {
public:
    string apply(string s){
        string news = "";
        // cout<<s<<": ";
        for(char ch: s){
            char chh = (ch-'a'+1)%26+'a';
            news.push_back(chh);
        }
        // cout<<news<<endl;
        return news;
    }
    
    long long countPairs(vector<string>& words) {
        unordered_map<string, long> ump;
        long long ans = 0;
        for(string w: words){
            if(ump[w] != 0){
                ans += ump[w];
            }
            
            string neword = w;
            for(int t=1; t<26; t++){
                neword = apply(neword);
                if(ump[neword] != 0){
                    ans += ump[neword];
                }
            }

            ump[w]++;
        }

        return ans;
    }
};