// Last updated: 6/11/2026, 11:38:20 AM
class Solution {
public:
    vector<string> all;
    int n;
    void rec(string &s, int open){
        int close = s.size() - open;
        if(close>open) return;
        if(s.size() == n){
            if(open == close){
                all.push_back(s);
                cout<<s<<endl;
            }
            return;
        }
        s.push_back('(');
        rec(s, open+1);
        s.pop_back();

        s.push_back(')');
        rec(s, open);
        s.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        this->n = 2*n;
        string s = "";
        rec(s, 0);
        return all;
    }
};