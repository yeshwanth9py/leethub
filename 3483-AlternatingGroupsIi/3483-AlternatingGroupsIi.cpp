// Last updated: 6/11/2026, 11:17:59 AM
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        if(n<k) return 0;
        int i = 0;
        int j = -1;
        int cnt = 0;
        while(i<n){
            while(j+1<2*n && (j<i || colors[(j+1)%n] != colors[j%n])){
                j++;
            }
            int curlen = j-i+1;
            // cout<<curlen<<endl;
            cnt += max(0, curlen-k+1);
            if(j>=n){
                int extralen = j-n+1;
                cnt -= max(0, extralen-k+1);
                return cnt;
            }
            if(i>j){ 
                i++;
                j=i-1;
            }else{
                j = j+1;
                i = j;
            }
        }

        return cnt;
    }
};