// Last updated: 6/11/2026, 11:38:38 AM
class Solution {
public:
    int maxArea(vector<int>& arr) {
        int n = arr.size();
        int i=0;
        int j=n-1;
        int marea = 0;
        while(i<j){
            int cura = min(arr[j], arr[i])*(j-i);
            marea = max(marea, cura);
            if(arr[i]<arr[j]){
                i++;
            }else{
                j--;
            }
        }

        return marea;
        
    }
};