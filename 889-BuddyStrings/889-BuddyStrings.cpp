// Last updated: 6/11/2026, 11:30:46 AM
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s == goal){
            set<char> s1(s.begin(), s.end());
            return s1.size()!=s.size();
        }

        if(s.size() != goal.size()){
            return false;
        }

        vector<int> wrongs;
        for(int i=0; i<s.size(); i++){
            if(s[i]!=goal[i]){
                wrongs.push_back(i);
            }
        }

        if(wrongs.size() == 2){
            swap(s[wrongs[0]], s[wrongs[1]]);
            return s == goal;
        }
        return false;
    }
};