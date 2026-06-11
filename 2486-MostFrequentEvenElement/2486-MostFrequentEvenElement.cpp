// Last updated: 6/11/2026, 11:22:18 AM
class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> ump;
        int maxfreq = 0;
        int ans = 1e9;

        for(int el: nums){
            if(el%2 != 0) continue;
            if(ump.find(el)!=ump.end()){
                ump[el]++;
                if(ump[el]>maxfreq){
                    maxfreq = ump[el];
                    ans = el;
                }else if(ump[el]==maxfreq){
                    ans = min(ans, el);
                }
            }else{
                ump[el] = 1;
                if(ump[el]>maxfreq){
                    maxfreq = ump[el];
                    ans = el;
                }else if(ump[el]==maxfreq){
                    ans = min(ans, el);
                }
            }
        }

        if(ans>=1e9) return -1;
        return ans;


    }
};