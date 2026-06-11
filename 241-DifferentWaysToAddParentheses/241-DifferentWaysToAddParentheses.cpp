// Last updated: 6/11/2026, 11:34:14 AM
class Solution {
public:
    vector<int> diffWaysToCompute(string s) {
        vector<int> ans;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '+' || s[i] == '-' || s[i]=='*'){
                vector<int> leftpv = diffWaysToCompute(s.substr(0, i));
                vector<int> rightpv = diffWaysToCompute(s.substr(i+1));
                for(int x =0; x<leftpv.size(); x++){
                    for(int y=0; y<rightpv.size(); y++){
                        if(s[i] == '+'){
                            ans.push_back(leftpv[x]+rightpv[y]);
                        }else if(s[i] == '-'){
                            ans.push_back(leftpv[x]-rightpv[y]);
                        }else{
                            ans.push_back(leftpv[x]*rightpv[y]);
                        }
                    }
                }
            }
        }
        if(ans.size()==0){
            ans.push_back(stoi(s));
        }
        return ans;
    }
};