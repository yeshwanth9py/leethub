// Last updated: 6/11/2026, 11:10:35 AM
class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<int> arr(101, 0);
        for(int el: bulbs){
            arr[el] = !arr[el];
        }
        vector<int> ans;
        for(int i=1; i<=100; i++){
            if(arr[i] == 1){
                ans.push_back(i);
            }
        }

        return ans;
    }
};