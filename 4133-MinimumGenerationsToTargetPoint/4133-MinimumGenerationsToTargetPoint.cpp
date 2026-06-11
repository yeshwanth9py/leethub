// Last updated: 6/11/2026, 11:12:13 AM
class Solution {
public:
    unordered_map<int, int> ump;
    int getcode(int x, int y, int z){
        int ans = ((x<<6) | (y<<3) | (z));
        return ans;
    }
    
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
        int ans = 0;
        for(auto el: points){
            int x1 = el[0];
            int y1 = el[1];
            int z1 = el[2];
            if(x1 == target[0] && y1 == target[1] && z1 == target[2]){
                return ans;
            }
            
            int code = getcode(x1, y1, z1);
            ump[code] = 1;
        }

        bool ng = 1;
        while(ng){
            ng = 0;
            ans++;
            vector<vector<int>> npoints;
            npoints = points;
            for(int i=0; i<points.size(); i++){
                auto el = points[i];
                int x1 = el[0];
                int y1 = el[1];
                int z1 = el[2];

                for(int j=i+1; j<points.size(); j++){
                    auto oel = points[j];
                    int x2 = oel[0];
                    int y2 = oel[1];
                    int z2 = oel[2];

                    if(x1 == x2 && y1 == y2 && z1 == z2) continue;

                    int nx = (x1+x2)/2;
                    int ny = (y1+y2)/2;
                    int nz = (z1+z2)/2;

                    if(nx == target[0] && ny == target[1] && nz == target[2]){
                        return ans;
                    }

                    int unicode = getcode(nx, ny, nz);
                    if(ump.find(unicode) == ump.end()){
                        npoints.push_back({nx, ny, nz});
                        ng = 1;
                        ump[unicode] = 1;
                    }
                }
            }

            points = npoints;
        }

        return -1;
    }
};