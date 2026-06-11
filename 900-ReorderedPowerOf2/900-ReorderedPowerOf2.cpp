// Last updated: 6/11/2026, 11:30:40 AM
class Solution {
public:
    bool reorderedPowerOf2(int n) {
        // unordered_map<string, bool> ump;
        string numb = to_string(n);
        sort(numb.begin(), numb.end());
        for(int i=0; i<31; i++){
            int curn = (1LL<<i);
            string temp = to_string(curn);
            sort(temp.begin(), temp.end());
            if(temp == numb){
                return 1;
            }
            // cout<<temp<<" ";
            // ump[temp] = 1;
        }
        return 0;
    }
};