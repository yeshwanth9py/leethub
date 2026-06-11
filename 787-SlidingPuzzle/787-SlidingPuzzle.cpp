// Last updated: 6/11/2026, 11:31:18 AM
class Solution {
public:
    vector<vector<int>> moves = {
        {1, 3},
        {0, 2, 4},
        {1, 5},
        {0, 4},
        {3, 5, 1},
        {4, 2}
    };

    string process(vector<vector<int>> &arr){
        string cur = "";
        for(int i=0; i<2; i++){
            for(int j=0; j<3; j++){
                cur += char(arr[i][j] + '0');
            }
        }
        return cur;
    }

    int slidingPuzzle(vector<vector<int>>& arr) {
        string start = "123450";
        string end = process(arr);
        if(start == end) return 0;

        queue<string> q;
        q.push(start);
        unordered_set<string> vis;
        vis.insert(start);
        int steps = 0;

        while(!q.empty()){
            int sz = q.size();
            steps++;
            for(int i=0; i<sz; i++){
                auto tel = q.front(); q.pop();
                int pz = tel.find('0');
                string temp = tel;
                for(int pn: moves[pz]){
                    swap(temp[pn], temp[pz]);
                    if(vis.find(temp) == vis.end()){
                        q.push(temp);
                        vis.insert(temp);
                        if(temp == end) return steps;
                    }
                    swap(temp[pn], temp[pz]);
                }
            }
        }

        return -1;
    }
};












