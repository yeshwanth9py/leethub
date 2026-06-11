// Last updated: 6/11/2026, 11:13:44 AM
class Solution {
public:
    int minCost(int n) {
        vector<int> myt;
        myt.push_back(n);

        int cost = 0;
        while(1){
            bool brk = 1;
            vector<int> nmyt;
            for(int el: myt){
                if(el != 1){
                    nmyt.push_back(el/2);
                    nmyt.push_back((el/2)+(el%2));
                    cost += (el/2)*((el/2)+(el%2));
                    brk = 0;
                }
            }
            if(brk == 1) break;
            myt = nmyt;
        }

        return cost;
    }
};