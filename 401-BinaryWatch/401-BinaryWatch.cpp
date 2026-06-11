// Last updated: 6/11/2026, 11:33:21 AM
class Solution {
public:
    void rec(int idx, vector<int> &months, unordered_map<int, set<int>> &umps, int sum, int left, int givl){
        if(left < 0) return;
        if(idx == months.size()){
            if(left == 0 && sum<60){
                umps[givl].insert(sum);
            }
            return;
        }

        rec(idx+1, months, umps, sum+months[idx], left-1, givl);
        rec(idx+1, months, umps, sum, left, givl);
    }

    vector<string> readBinaryWatch(int to) {
        unordered_map<int, vector<int>> umph;

        umph[0].push_back(0);
        umph[1].push_back(8);
        umph[1].push_back(4);
        umph[1].push_back(2);
        umph[1].push_back(1);

        umph[2].push_back(10);
        umph[2].push_back(9);
        umph[2].push_back(6);
        umph[2].push_back(5);
        umph[2].push_back(3);

        umph[3].push_back(11);
        umph[3].push_back(7);

        
        vector<int> months = {32, 16, 8, 4, 2, 1};
        unordered_map<int, set<int>> umps;
        umps[0].insert(0);

        for(int tak=1; tak<=6; tak++){
            rec(0, months, umps, 0, tak, tak);
        }

        set<string> all;
        for(int i=0; i<=to; i++){
            int hrs = i;
            int mins = to-i;

            for(int el: umph[hrs]){
                for(int el2: umps[mins]){
                    string cur = to_string(el) + ":";
                    string m = to_string(el2);
                    while(m.size()<=1){
                        m = '0'+m;
                    }
                    cur = cur+m;
                    all.insert(cur);
                }
            }
        }


        return vector<string> (all.begin(), all.end());


        

    }
};