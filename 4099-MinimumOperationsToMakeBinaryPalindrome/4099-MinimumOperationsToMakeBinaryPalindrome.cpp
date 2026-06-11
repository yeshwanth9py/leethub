// Last updated: 6/11/2026, 11:12:44 AM
class Solution {
public:
    vector<int> allpal;
    bool ispalind(int num){
        int num2 = 0;
        int len = log2(num)+1;
        int j = len-1;
        for(int i=0; i<(len/2); i++){
            if(((num&(1LL<<i)) == 0) && ((num&(1LL<<j)) == 0)){
                j--;
                continue;
            }else if(((num&(1LL<<i)) != 0) && ((num&(1LL<<j)) != 0)){
                j--;
                continue;
            }else{
                return 0;
            }
        }
        // cout<<num<<" ";
        return 1;
    }
    vector<int> minOperations(vector<int>& nums) {
        for(int i=1; i<=10000; i++){
            if(ispalind(i)){
                allpal.push_back(i);
            }
        }

        vector<int> ans;
        for(int el: nums){
            auto it = lower_bound(allpal.begin(), allpal.end(), el);
            int op1 = abs((*it) - el);
            if(it!=allpal.begin()){
                it = prev(it);
                int op2 = abs((*it)-el);
                op1 = min(op1, op2);
            }
            
            ans.push_back(op1);
        }

        
        return ans;
        
    }
};