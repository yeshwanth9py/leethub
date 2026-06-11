// Last updated: 6/11/2026, 11:13:20 AM
class Solution {
public:
    int minSwaps(vector<int>& arr, vector<int>& brr) {
        int n = arr.size();
        
        int badel = -1;
        int badct = 0;

        vector<vector<int>> goodp;

        int ans = 0;
        for(int i=0; i<n; i++){
            if(arr[i] == brr[i]){
                if(badel == -1){
                    badel = arr[i];
                    badct = 1;
                }else if(arr[i] == badel){
                    badct++;
                }else{
                    badct--;
                    goodp.push_back({1, arr[i], badel});
                    ans++;
                    if(badct == 0){
                        badel = -1;
                    }
                }
            }else{
                goodp.push_back({0, arr[i], brr[i]});
            }
        }

        if(badct == 0){
            return ans;
        }
        sort(goodp.begin(), goodp.end());
        reverse(goodp.begin(), goodp.end());

        // cout<<badel<<" "<<badct<<endl;
        for(auto el: goodp){
            int u = el[1];
            int v = el[2];
            int s = el[0];
            if(s == 1){
                if(u!=badel && v!=badel){
                    if(badct>=2){
                        ans += 1;
                        badct-=2;
                    }else{
                        ans += 1;
                        badct--;   
                    }
                    if(badct == 0){
                        return ans;
                    }
                }
            }else{
                if(u!=badel && v!=badel){
                    badct--;
                    ans += 1;
                    if(badct == 0){
                        return ans;
                    }
                }   
            }
        }

        return -1;

        
    }
};