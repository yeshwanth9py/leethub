// Last updated: 6/11/2026, 11:27:42 AM
class Solution {
public:
    vector<string> vec;
    int n;
    void rec(int ind, string &s){
        if(ind == n){
            vec.push_back(s);
            return;
        }

        for(char ch='a'; ch<='c'; ch++){
            if(s.empty() || s.back() != ch){
                s.push_back(ch);
                rec(ind+1, s);
                s.pop_back();
            }
        }
    }

    string getHappyString(int n, int k) {
        string s = "";
        this->n = n;
        sort(vec.begin(), vec.end());
        rec(0, s);
        sort(vec.begin(), vec.end());
        if(vec.size()>=k) return vec[k-1];
        return "";
    }
};