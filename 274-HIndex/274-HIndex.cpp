// Last updated: 6/11/2026, 11:34:09 AM
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int maxc = *max_element(citations.begin(), citations.end()) + 2;
        // cout<<maxc<<" ";
        // const int sz = maxc;
        vector<int> arr(maxc, 0);
        for(int el: citations){
            arr[el]++;
        }

        
        
        for(int i=maxc-2; i>=0; i--){
            arr[i] += arr[i+1];
            if(arr[i]>=i){
                return i;
            }
        }
        

        return -1;

    }
};