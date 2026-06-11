// Last updated: 6/11/2026, 11:09:33 AM
class Solution {
public:
    vector<int> scoreValidator(vector<string>& eve) {
        int cnt = 0;
        int sc = 0;
        for(auto s: eve){
            if(s == "W"){
                cnt++;
                if(cnt>=10) return {sc, cnt};
            }else if(s == "WD"){
                sc++;
            }else if(s == "NB"){
                sc++;
            }else{
                sc += stoi(s);
            }
        }

        return {sc, cnt};
    }
};