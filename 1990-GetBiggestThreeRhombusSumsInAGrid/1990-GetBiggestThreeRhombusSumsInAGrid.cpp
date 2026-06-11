// Last updated: 6/11/2026, 11:25:31 AM
class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        set<int> st;   // store unique sums
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                // size 0 rhombus
                st.insert(grid[i][j]);
                
                for(int k=1;;k++){
                    
                    if(i + 2*k >= m || j-k < 0 || j+k >= n) break;
                    
                    int sum = 0;
                    
                    int r=i, c=j;
                    
                    // top -> right
                    for(int t=0;t<k;t++){
                        sum += grid[r+t][c+t];
                    }
                    
                    // right -> bottom
                    for(int t=0;t<k;t++){
                        sum += grid[r+k+t][c+k-t];
                    }
                    
                    // bottom -> left
                    for(int t=0;t<k;t++){
                        sum += grid[r+2*k-t][c-t];
                    }
                    
                    // left -> top
                    for(int t=0;t<k;t++){
                        sum += grid[r+k-t][c-k+t];
                    }
                    
                    st.insert(sum);
                }
            }
        }
        
        vector<int> res(st.begin(), st.end());
        sort(res.begin(), res.end(), greater<int>());
        
        if(res.size()>3) res.resize(3);
        
        return res;
    }
};