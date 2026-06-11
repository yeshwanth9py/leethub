// Last updated: 6/11/2026, 11:32:12 AM
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int prev = -1;

        sort(pairs.begin(), pairs.end(), [](vector<int> &a, vector<int> &b){
            return a[1]<b[1];
        });
        
        int n = pairs.size();
        int cur = 0;
        int cnt = 0;
        while(cur<n){
            if(prev==-1 || (pairs[cur][0]>pairs[prev][1])){
                cnt++;
                prev = cur;
                cur++;
            }else{
                cur++;
            }
        }

        return cnt;


    }
};