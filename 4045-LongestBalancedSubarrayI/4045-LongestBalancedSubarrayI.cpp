// Last updated: 6/11/2026, 11:13:34 AM
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        
        for(int i=0; i<n; i++){
            unordered_map<int, int> dis;
            int cur = 0;
            for(int j=i; j<n; j++){
                int el = nums[j];
                if(dis[el] == 0){
                    if(el%2 == 0){
                        cur++;
                    }else{
                        cur--;
                    }
                }
                if(cur == 0){
                    ans = max(ans, j-i+1);
                }
                dis[el] = 1;
            }
        }

        return ans;
    }
};