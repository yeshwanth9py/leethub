// Last updated: 6/11/2026, 11:22:29 AM
class Solution {
public:
    bool isvalid(vector<int> &nums, string s){
        for(int i=0; i<s.length(); i++){
            if(s[i]=='I'){
                if(nums[i]<nums[i+1]){
                    continue;
                }else{
                    return false;
                }
            }else if(s[i] == 'D'){
                if(nums[i]>nums[i+1]){
                    continue;
                }else{
                    return false;
                }
            }
        }
        return true;

    }
    string smallestNumber(string pattern) {
        vector<int> nums;
        string ans = "";
        for(int i=0; i<=pattern.length(); i++){
            nums.push_back(i+1);
        }
        do{
            ans = "";
            if(isvalid(nums, pattern)){
                for(int el: nums){
                    ans += to_string(el);
                }
                
                return ans;
             }
        }while(next_permutation(nums.begin(), nums.end()));
        
        return ans;


    }
};