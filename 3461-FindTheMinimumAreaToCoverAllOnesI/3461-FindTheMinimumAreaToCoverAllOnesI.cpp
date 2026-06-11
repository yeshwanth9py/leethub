// Last updated: 6/11/2026, 11:18:09 AM
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int c1 = 0;
        int c2 = m-1;
        int r1 = 0;
        int r2 = n-1;

        vector<int> verti(m, 0);
        vector<int> horiz(n, 0);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    horiz[i] = 1;
                    verti[j] = 1;
                }
            }
        }

        while(c1<=c2 && verti[c1] == 0){
            c1++;
        }
        

        while(c1<=c2 && verti[c2] == 0){
            c2--;
        }

        while(r1<=r2 && horiz[r1] == 0){
            r1++;
        }

        while(r1<=r2 && horiz[r2] == 0){
            r2--;
        }
        cout<<c1<<" "<<c2<<" "<<r1<<" "<<r2<<endl;

        int area = ((c2-c1+1) * (r2-r1+1));
        return area;
    }
};