// Last updated: 6/11/2026, 11:28:33 AM
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        for(int i=0; i<points.size()-1; i++){
            int x = points[i][0]; int y = points[i][1];
            int nx = points[i+1][0]; int ny = points[i+1][1];
            
            ans += max(abs(nx-x), abs(ny-y));
            
        }
        return ans;
    }
};