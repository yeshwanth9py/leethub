// Last updated: 6/11/2026, 11:24:27 AM
class Solution {
public:
    int minOperations(vector<vector<int>>& arr, int x) {
        vector<int> ans;
        int n = arr.size();
        int m = arr[0].size();


        int v = arr[0][0];
        bool anspos = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(arr[i][j] != v){
                    anspos = 0;
                    break;
                }
            }
        }

        if(anspos) return 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans.push_back(arr[i][j]);
            }   
        }

        sort(ans.begin(), ans.end());

        int md = (ans.size()/2);
        int asans = 0;
        for(int el: ans){
            int cur = abs(el-ans[md]);
            if(cur%x != 0) return -1;
            asans += (cur/x); 
        }

        return asans;
    }
};

