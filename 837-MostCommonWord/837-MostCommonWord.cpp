// Last updated: 6/11/2026, 11:30:57 AM
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> banned_map;
        unordered_map<string, int> ans_map;

        for(string &el: banned){
            transform(el.begin(), el.end(), el.begin(), ::tolower);
            banned_map[el]++;
        }

        string word = "";
        int ansf = 0;
        string anss;

        for(char el: paragraph){
            if(el>='a' && el<='z'){
                word+=el;
            }else if(el>='A' && el<='Z'){
                char temp = el+('a'-'A');
                word += temp;
            }else{
                if(word!="" && banned_map.find(word)==banned_map.end()){
                    ans_map[word]++;
                    if(ans_map[word]>ansf){
                        ansf = ans_map[word];
                        anss = word;
                    }
                }
                word = "";
            }
        }

        if(word!=""){
            if(banned_map.find(word)==banned_map.end()){
                ans_map[word]++;
                if(ans_map[word]>ansf){
                    ansf = ans_map[word];
                    anss = word;
                }
            }
            
        }

        return anss;


    }
};