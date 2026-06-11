// Last updated: 6/11/2026, 11:27:32 AM
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n = numCourses;
        vector<vector<int>> adjl(n, vector<int>());

        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        for(auto pr: prerequisites){
            adjl[pr[0]].push_back(pr[1]);
            dist[pr[0]][pr[1]] = 1;
        }

        
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(dist[i][j] > dist[i][k]+dist[k][j]){
                        dist[i][j] = dist[i][k]+dist[k][j];
                    }
                }
            }
        }

        vector<bool> ans;

        for(auto que: queries){
            int a = que[0];
            int b = que[1];
            if(dist[a][b]<1e9){
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }
        }

        return ans;






    }
};