// Last updated: 6/11/2026, 11:27:50 AM
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end());
        int cur = 0;
        int i = 0;
        int ans = 0;
        while(i<arr.size()){
            int st = arr[i][0]-1;
            if(cur<st){
                ans += 2*(st-cur);
                cur = st;
            }
 
            vector<int> temp(10, 0);
            int j = i;
            while(j<arr.size() && (arr[j][0]-1)==cur){
                int ten = arr[j][1]-1;
                temp[ten] = 1;
                j++;
            }

            for(int k=0; k<10; k++){
                temp[k] += (k-1>=0?temp[k-1]:0);
            }
            
            if((temp[4] - temp[0] == 0) && (temp[8]-temp[4]) == 0){
                ans += 2;
            }else if((temp[4] - temp[0] == 0) || ((temp[8]-temp[4]) == 0) || (temp[6] - temp[2] == 0)){
                ans += 1;
            }

            i = j;
            cur++;
        }

        ans += 2*(n-cur);

        return ans;

    }
};