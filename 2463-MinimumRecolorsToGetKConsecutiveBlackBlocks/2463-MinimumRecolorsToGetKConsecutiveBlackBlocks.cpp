// Last updated: 6/11/2026, 11:22:25 AM
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.length();
        int i = 0;
        int j = -1;
        int w = 0;
        int b = 0;

        int ans = k;
        while(i<n){
            while(j+1<n && j-i+1<k){
                j++;
                if(blocks[j] == 'W'){
                    w++;
                }else{
                    b++;
                }
            }
            if(j-i+1==k){
                ans = min(ans, w);
            }

            if(i>j){
                i++;
                j = i-1;
            }else{
                if(blocks[i] == 'W'){
                    w--;
                }else{
                    b--;
                }
                i++;
            }
        }
        return ans;
    }
};