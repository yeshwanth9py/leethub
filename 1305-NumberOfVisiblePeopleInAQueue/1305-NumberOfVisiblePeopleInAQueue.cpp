// Last updated: 6/11/2026, 11:28:56 AM
class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& arr) {
        int n = arr.size();
        vector<int> answe(n, 0);
        vector<int> vec;
        for(int i=n-1; i>=0; i--){
            if(vec.size()>0){
                int lo = 0;
                int hi = vec.size()-1;
                int ans = -1;
                while(lo<=hi){
                    int mid = (lo+hi)/2;
                    if(arr[vec[mid]] < arr[i]){
                        ans = mid;
                        hi = mid-1;
                    }else{
                        lo = mid+1;
                    }
                }
                if(ans != -1){
                    ans = max(ans-1, 0);
                    answe[i] = (vec.size()-ans);
                }else if(vec.size()>0){
                    answe[i] = 1;
                }   
            }
           
           while(vec.size()>0 && arr[vec.back()]<=arr[i]){
               vec.pop_back();
           }
            vec.push_back(i);
        }

        return answe;
    }
};