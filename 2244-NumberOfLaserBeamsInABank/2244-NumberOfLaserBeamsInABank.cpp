// Last updated: 6/11/2026, 11:23:50 AM
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> arr;
        int n = bank.size();
        int m = bank[0].size();

        for(int i=0; i<n; i++){
            int no1 = 0;
            for(int j=0; j<m; j++){
                no1 += (bank[i][j] == '1');
            }
            if(no1 == 0) continue;
            arr.push_back(no1);
        }
        if(arr.size() <= 1) return 0;
        
        int ans = 0;
        for(int i=0; i<arr.size()-1; i++){
            ans += (arr[i]*arr[i+1]);
        }

        return ans;


    }
};