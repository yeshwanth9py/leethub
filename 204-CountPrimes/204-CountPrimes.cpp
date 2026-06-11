// Last updated: 6/11/2026, 11:34:56 AM
class Solution {
public:
    int countPrimes(int n) {
        int cnt = 0;

        vector<int> marked(n, 1);
        for(int i=2; i*i<=n-1; i++){
            if(marked[i]){
                for(int j=i*i; j<=n-1; j=j+i){
                    marked[j] = 0;
                }
            }
        }

        for(int i=2; i<=n-1; i++){
            if(marked[i]){
                cnt++;
            }
        }

        return cnt;
    }
};