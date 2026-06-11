// Last updated: 6/11/2026, 11:29:45 AM
class Solution {
public:
    bool check(int mid, vector<int>& weights, int days){
        int anss = 0;
        int ansd = 0;
        for(int i=0; i<weights.size(); i++){
            if(anss>=weights[i]){
                anss -= weights[i];
            }
            else{
                ansd+=1;
                anss = mid-weights[i];
            }
        }
        return ansd<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = 1e9;
        int ans =0;
        while(low<=high){
            int mid = (low+high)/2;
            if(check(mid, weights, days)){
                ans = mid;
                high = mid-1;
            } else{
                low = mid+1;
            }
        }

        return ans;
    }
};