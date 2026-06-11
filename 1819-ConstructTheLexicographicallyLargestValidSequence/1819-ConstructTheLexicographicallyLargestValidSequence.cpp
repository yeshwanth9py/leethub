// Last updated: 6/11/2026, 11:26:18 AM
class Solution {
public:
    vector<vector<int>> allans;
    void printans(){
        for(auto v: allans){
            for(auto el: v){
                cout<<el<<" ";
            }
            cout<<endl;
        }
    }
    void rec(int ind, vector<int> &vis, vector<int> &ans, int n){
        if(ind == ans.size()){
            allans.push_back(ans);
            return;
        }
        // printans();
        if(allans.size()==1){
            return;
        }
        if(ans[ind]!=-1){
            rec(ind+1, vis, ans, n);
            return;
        }
        for(int i=n; i>=1; i--){
            if(vis[i] == -1){
                if(i==1){
                    vis[i] = 1;
                    ans[ind] = i;
                    rec(ind+1, vis, ans, n);
                    if(allans.size()==1){
            return;
        }
                    vis[i] = -1;
                    ans[ind] = -1;
                }else{
                    if(i+ind<ans.size() && ans[i+ind]==-1){
                        vis[i] = 1;
                        ans[ind] = i;
                        ans[ind+i] = i;
                        rec(ind+1, vis, ans, n);
                        if(allans.size()==1){
            return;
        }
                        vis[i] = -1;
                        ans[ind] = -1;
                        ans[ind+i] = -1;
                    }
                }
            }
        }

    }

    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2*n-1, -1);
        vector<int> vis(n+1, -1);
        allans.clear();
        rec(0,vis,ans,n);
        printans();
        

        return allans[0];
    }
};