// Last updated: 6/11/2026, 11:30:39 AM
class Solution {
public:
    int fab(int f, int s, vector<int>& arr, set<int> &se){
        int len = 2;
        int prev = arr[f];
        int cur = arr[s];
        while(true){
            int num = prev+cur;
            if(se.find(num)!=se.end()){
                prev = cur;
                cur = num;
                len++;
            }else{
                break;
            }
        }

        return len;
    }
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        set<int> se;
        int ml = 0;
        for(int i=0; i<n; i++){
            se.insert(arr[i]);
        }
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(arr[j]>arr[i]){
                    int len = fab(i, j, arr, se);
                    if(len>2){
                        ml = max(ml, len);
                    }
                }
            }
        }
        return ml;
    }
};