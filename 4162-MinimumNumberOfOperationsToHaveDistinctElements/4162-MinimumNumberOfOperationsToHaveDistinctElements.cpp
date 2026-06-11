// Last updated: 6/11/2026, 11:11:17 AM
class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> ump;
        int n = nums.size();
        int f = -1;
        for(int i=0; i<n; i++){
            ump[nums[i]] += 1;
        }

        if(ump.size() == n) return 0;

        int i=0;
        int j=-1;
        int nod = ump.size();
        int op = 0;
        while(i<n){
            op++;
            while(j+1<n && j+1-i+1<=3){
                j++;
                ump[nums[j]]--;
                if(ump[nums[j]] == 0){
                    nod--;
                }
            }
            if(nod == n-1-j){
                return op;
            }
            i = j+1;
        }

        return op;
    }
};


