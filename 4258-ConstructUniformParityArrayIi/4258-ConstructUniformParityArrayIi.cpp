// Last updated: 6/11/2026, 11:09:56 AM
class Solution {
public:
    bool caniforme(vector<int> &arr){
        for(int i=1; i<arr.size(); i++){
            if(arr[i]%2 == 1){
                return 0;
            }
        }
        return 1;
    }
    
    bool caniformo(vector<int> &arr){
        return 1;
    }
    
    bool uniformArray(vector<int>& arr) {
        if(arr.size() == 1) return 1;
        sort(arr.begin(), arr.end());
        if(arr[0]%2 == 0){
            if(caniforme(arr)){
                return 1;
            }
        }else{
            if(caniformo(arr)){
                return 1;
            }
        }
        
        return 0;
        
    }
};