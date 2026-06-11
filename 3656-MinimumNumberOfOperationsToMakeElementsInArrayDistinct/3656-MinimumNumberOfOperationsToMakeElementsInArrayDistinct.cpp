// Last updated: 6/11/2026, 11:16:55 AM
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int nod = 0;
        int n = nums.size();
        unordered_map<int, int> ump;
        
        for(int el: nums){
            ump[el]++;
        }
        for(auto el: ump){
            if(el.second >1){
                nod++;
            }
        }
        
        if(nod == 0) return 0;
        for(int i=0; i<n; i=i+3){
            ump[nums[i]]--;
            if(ump[nums[i]] == 1){
                nod--;
            }
            if(i+1<n){
                ump[nums[i+1]]--;
                if(ump[nums[i+1]] == 1){
                    nod--;
                }
            }
            if(i+2<n){
                ump[nums[i+2]]--;
                if(ump[nums[i+2]] == 1){
                    nod--;
                }
            }
            if(nod<=0){
                if(i == 0){
                    return 1;
                }else{
                    return 1+(i/3);
                }
            }
        }
        return (n/3)+1; 
    }
};