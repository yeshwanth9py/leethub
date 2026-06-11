// Last updated: 6/11/2026, 11:30:02 AM
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        sort(points.begin(), points.end(), [](vector<int> p1, vector<int> p2){
            return (abs(pow((p1[0]),2) + pow((p1[1]),2))) < (abs(pow((p2[0]),2) + pow((p2[1]),2)));
        });

        vector<vector<int>> ans;
        for(int i=0; i<k; i++){
            ans.push_back(points[i]);
        }

        return ans;
        

        


    }
};