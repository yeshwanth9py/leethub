// Last updated: 6/11/2026, 11:21:11 AM
class Solution {
public:
    vector<vector<int>> findlcp(string &w){
        int n = w.size();
        vector<vector<int>> lcp(n, vector<int>(n, 0));
        // cout<<w<<" ";
        for(int i=n-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(w[i] != w[j]){
                    lcp[i][j] = 0;
                }else{
                    lcp[i][j] = 1;
                    if(i+1<n && j+1<n){
                        lcp[i][j] += lcp[i+1][j+1];
                    }
                }
            }
        }

        return lcp;
    }

    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string ans(n, '#');

        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(lcp[j][i] != 0){
                    ans[i] = ans[j];
                    break;
                }
            }

            if(ans[i] == '#'){
                vector<int> forbidden(26, 0);
                for(int j=0; j<i; j++){
                    if(lcp[j][i] == 0){
                        forbidden[ans[j]-'a'] = 1;
                    }
                }
                for(int w=0; w<26; w++){
                    if(forbidden[w] == 0){
                        ans[i] = char(w+'a');
                        break;
                    }
                }
            }
            if(ans[i] == '#') return "";
        }

        vector<vector<int>> duplcp = findlcp(ans);

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<duplcp[i][j]<<" ";
            }
            cout<<endl;
        }

        return ((duplcp == lcp)?ans:"");
    }
};