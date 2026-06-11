// Last updated: 6/11/2026, 11:38:46 AM
class Solution {
public:
    string convert(string s, int m) {
        int r = 0;
        int c = 0;
        if(m == 1) return s;
        int i = 0;
        int n = s.size();

        unordered_map<int, vector<char>> ump;

        int typ = 0;
        while(i<s.size()){
            if(typ == 0){
                ump[r].push_back(s[i]);
                r++;
            }else{
                ump[r].push_back(s[i]);
                r--;
            }
            i++;
            if(r<0){
                r = 1;
                typ = 0;
            }
            if(r>=m){
                r=m-2;
                typ = 1;
            }
        }

        string ans = "";
        for(int r=0; r<m; r++){
            for(char ch: ump[r]){
                ans.push_back(ch);
            }
        }
        return ans;
    }
};


