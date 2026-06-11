// Last updated: 6/11/2026, 11:20:40 AM
class Solution {
public:
    string sortVowels(string s) {
        vector<char> temp;
        vector<int> pos;
        unordered_set<char> us = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        string res = s;

        for(int i=0; i<s.length(); i++){
            char ch = s[i];
            if(us.find(ch)!=us.end()){
                temp.push_back(ch);
                pos.push_back(i);
            }
        }
        
        sort(temp.begin(), temp.end());

        int i=0;
        for(int p: pos){
            res[p] = temp[i];
            i++;
            if(i == temp.size()) break;
        }
        return res;

    }
};