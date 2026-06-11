// Last updated: 6/11/2026, 11:32:46 AM
class Solution {
public:
    int findMaxLength(vector<int>& arr) {
        int curs = 0;
        int n = arr.size();
        unordered_map<int, int> ump;
        ump[0] = -1;
        int ans = 0;
        for(int i=0; i<n; i++){
            if(arr[i] == 0){
                curs--;
            }else{
                curs++;
            }
            if(ump.find(curs) != ump.end()){
                ans = max(ans, i-ump[curs]);
            }else{
                ump[curs] = i;
            }
            
        }
        return ans;
    }
};