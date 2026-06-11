// Last updated: 6/11/2026, 11:31:29 AM
class Solution {
public:
    string makeLargestSpecial(string s) {
        if(s.size() == 0) return s;
        int cnt = 0;
        int j=0;
        vector<string> all;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '1'){
                cnt++;
            }else{
                cnt--;
            }

            if(cnt == 0){
                string t = s.substr(j+1, i-1-j);
                t = makeLargestSpecial(t);
                t = '1' + t + '0';
                all.push_back(t);
                j = i+1;
            }
        }
        sort(all.begin(), all.end(), [&](string a, string b){
           return a>b;
        });
        string temp = "";
        for(auto el: all){
            temp += el;
        }

        return temp;
        
    }
};