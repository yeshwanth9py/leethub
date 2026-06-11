// Last updated: 6/11/2026, 11:29:49 AM
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> count(n+1, 0);
        for(auto edg: trust){
            count[edg[0]]--;
            count[edg[1]]++;
        }
        for(int i=1; i<=n; i++){
            if(count[i] == n-1) return i;
        }
        return -1;
    }
};