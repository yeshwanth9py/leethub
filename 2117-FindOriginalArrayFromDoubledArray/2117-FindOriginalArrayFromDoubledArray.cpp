// Last updated: 6/11/2026, 11:24:57 AM
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& arr) {
        int n=arr.size();
        if((n%2) != 0) return {};

        unordered_map<int, int> ump;
        sort(arr.begin(), arr.end());

        vector<int> ans;

        for(int el: arr){
            if(el%2 == 0 && ump.find(el/2)!=ump.end() && ump[el/2]>0){
                ans.push_back(el/2);
                // ump.erase(el/2)/;
                ump[el/2]--;
            }else{
                ump[el] += 1;
            }
        }

        if(n/2 == ans.size()) return ans;
        return {};
    }
};