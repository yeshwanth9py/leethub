// Last updated: 6/11/2026, 11:21:45 AM
class Solution {
public:
    int similarPairs(vector<string>& words) {
        map<set<char>, int> um;
        for(string wor: words){
            set<char> temp;
            for(char ch: wor){
                temp.insert(ch);
            }
            if(um.find(temp)!=um.end()){
                um[temp]++;
            }else{
                um[temp]=1;
            }
        }

        int ans = 0;
        for (auto& p : um) {
            if (p.second > 1) {
                ans += (p.second * (p.second - 1)) / 2;
            }
        }


        return ans;
    }
};