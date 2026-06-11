// Last updated: 6/11/2026, 11:16:07 AM
class Solution {
public:
    string generateString(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        string ans(n+m-1, '#');

        for(int i=0; i<n; i++){
            if(s1[i] == 'T'){
                int j = i;
                while(j<i+m){
                    if(ans[j] == s2[j-i] || ans[j] == '#'){
                        ans[j] = s2[j-i];
                    }else{
                        return "";
                    }
                    j++;
                }
            }
        }

        vector<int> nof(n+m, 0);
        for(int i=0; i<n+m; i++){
            if(ans[i] == '#'){
                ans[i] = 'a';
                nof[i] = 1;
            }
        }

        for(int i=0; i<n; i++){
            if(s1[i] == 'F' && ans.substr(i, m) == s2){
                for(int j=i+m-1; j>=i; j--){
                    if(nof[j] == 1){
                        ans[j] = 'b';
                        nof[j] = 0;
                        break;
                    }
                }
                if(ans.substr(i, m) == s2){
                    return "";
                }
            }
        }

        return ans;
    }
};