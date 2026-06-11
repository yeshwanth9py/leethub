// Last updated: 6/11/2026, 11:25:14 AM
class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& arr, int k) {
        int n = arr.size();
        int m = arr[0].size();

        int r1 = 0;
        int r2 = n-1;
        int c1 = 0;
        int c2 = m-1;

        while(r1<r2 && c1<c2){
            vector<int> temp;
            for(int i=c1; i<=c2; i++){
                temp.push_back(arr[r1][i]);
            }

            for(int i=r1+1; i<=r2; i++){
                temp.push_back(arr[i][c2]);
            }

            for(int i=c2-1; i>=c1; i--){
                temp.push_back(arr[r2][i]);
            }

            for(int i=r2-1; i>=r1+1; i--){
                temp.push_back(arr[i][c1]);
            }

            // for(int el: temp){
            //     cout<<el<<" ";
            // }

            // cout<<endl;

            int kk = k%(temp.size());

            vector<int> temp2;

            for(int i=kk; i<temp.size(); i++){
                temp2.push_back(temp[i]);
            }

            for(int i=0; i<kk; i++){
                temp2.push_back(temp[i]);
            }

            int j = 0;
            for(int i=c1; i<=c2; i++){
                arr[r1][i] = temp2[j];
                j++;
            }

            
            for(int i=r1+1; i<=r2; i++){
                arr[i][c2] = temp2[j];
                j++;
            }

            for(int i=c2-1; i>=c1; i--){
                arr[r2][i] = temp2[j];
                j++;
            }


            for(int i=r2-1; i>=r1+1; i--){
                arr[i][c1] = temp2[j];
                j++;
            }

            r1++;
            r2--;
            c1++;
            c2--;
        }

        return arr;
    }
};