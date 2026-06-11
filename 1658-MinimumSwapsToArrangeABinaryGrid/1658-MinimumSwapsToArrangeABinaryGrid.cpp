// Last updated: 6/11/2026, 11:27:03 AM
class Solution {
public:
    int minSwaps(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<int> myar;
        for(int i=0; i<n; i++){
            int cntz = 0;
            for(int j=n-1; j>=0; j--){
                if(arr[i][j] != 0){
                    break;
                }else{
                    cntz++;
                }
            }
            myar.push_back(cntz);
        }

        vector<int> dup = myar;

        int i=0;
        int ans = 0;
        int targ = n-1;
        while(i<n-1){
            if(dup[i]>=targ){
                i++;
                targ = targ-1;
            }else{
                int j = i+1;
                int cos = 0;
                while(j<n && dup[j]<targ){
                    j++;
                }
                if(j == n){
                    return -1;
                }

                ans += j-i;
                while(j>i){
                    swap(dup[j], dup[j-1]);
                    j--;
                
                }
                targ = targ-1;
                i++;
            }
        }

        return ans;
        

    }
};