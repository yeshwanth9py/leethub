// Last updated: 6/11/2026, 11:27:13 AM
class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        int op = target[0];
        for(int i=1; i<n; i++){
            if(target[i]>target[i-1]){
                op += (target[i]-target[i-1]);
            }
        }
        return op;
    }
};