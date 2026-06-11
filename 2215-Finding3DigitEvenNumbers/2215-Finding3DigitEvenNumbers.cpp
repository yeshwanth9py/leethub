// Last updated: 6/11/2026, 11:23:58 AM
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        set<int> ans;

        for(int i=0; i<n; i++){
            if(digits[i] == 0) continue;
            string temp = to_string(digits[i]);
            for(int j = 0; j<n; j++){
                if(j == i) continue;
                temp += to_string(digits[j]);
                for(int k=0; k<n; k++){
                    if(k == i || k == j || (digits[k]%2 != 0)) continue;
                    temp += to_string(digits[k]);
                    ans.insert(stoll(temp));
                    temp.pop_back();
                }
                temp.pop_back();
            }
        }
        vector<int> ans2(ans.begin(), ans.end());
        sort(ans2.begin(), ans2.end());
        return ans2;
        
    }
};