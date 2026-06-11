// Last updated: 6/11/2026, 11:26:54 AM
class Solution {
public:
    int minCost(string s, vector<int>& arr) {
        int i=0;
        int j=-1;
        int n = arr.size();
        int pum = 0;
        int max1 = -1e9;

        int ans = 0;

        while(i<n){
            while(j+1<n && s[j+1] == s[i]){
                j++;
                pum += arr[j];
                if(arr[j]>max1){
                    max1 = arr[j];
                }
            }

            // cout<<i<<" "<<j<<" "<<pum;

            if(j-i+1>1 && pum>0){
                // cout<<"went ";
                ans = ans+(pum);
                // if(j-i+1>2){
                    ans -= (max1); 
                // }
                // cout<<"a: "<<ans<<endl;
            }

            if(i>j){
                i++;
                j=i-1;
                max1 = -1e9;
                // max2 = -1e9;
                pum = 0;
            }else{
                i = j+1;
                j = i-1;
                max1 = -1e9;
                // max2 = -1e9;
                pum = 0;
            }
        }

        return ans;
    }
};