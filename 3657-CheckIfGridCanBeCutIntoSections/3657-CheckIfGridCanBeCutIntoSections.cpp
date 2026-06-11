// Last updated: 6/11/2026, 11:16:54 AM
class Solution {
public:
    bool linesweep(vector<pair<int, int>> &vec){
        int mainv = 0;
        int lines = 0;
        for(auto el: vec){
            if(el.second == 1){
                mainv+=1;
            }else{
                mainv--;
            }

            if(mainv == 0){
                lines++;
            }
        }
        return lines>=3;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int, int>> xcord;
        vector<pair<int, int>> ycord;
        for(auto el: rectangles){
            xcord.push_back({el[0], 1});
            xcord.push_back({el[2], 0});
            ycord.push_back({el[1], 1});
            ycord.push_back({el[3], 0});
        }
        sort(xcord.begin(), xcord.end());
        sort(ycord.begin(), ycord.end());

        return linesweep(xcord) | linesweep(ycord);



    }
};