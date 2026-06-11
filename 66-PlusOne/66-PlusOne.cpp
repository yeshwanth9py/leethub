// Last updated: 6/11/2026, 11:37:23 AM
class Solution {
public:
    vector<int> plusOne(vector<int>& arr) {
        int i=arr.size()-1;
        vector<int> ans;
        int c = 1;
        while(i>=0){
            if(c == 0){
                ans.push_back(arr[i]);
            }else{
                if(arr[i] == 9){
                    c = 1;
                    ans.push_back(0);
                }else{
                    ans.push_back(arr[i]+1);
                    c = 0;
                }
            }
            i--;
        }
        if(c){
            ans.push_back(1);
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};