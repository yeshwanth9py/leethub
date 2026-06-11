// Last updated: 6/11/2026, 11:33:27 AM
class Solution {
public:
    vector<int> ans;
    int n;
    void dfs(int num){
        if(num>n) return;
        ans.push_back(num);
        for(int i=0; i<=9; i++){
            int nnum = num*10+i;
            dfs(nnum);
        }
    }
    vector<int> lexicalOrder(int n) {
        this->n = n;
        for(int i=1; i<=9; i++){
            if(i<=n){
                dfs(i);
            }
        }
        return ans;
    }
};