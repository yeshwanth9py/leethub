// Last updated: 6/11/2026, 11:14:56 AM
class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& arr, int k) {
        int n = arr.size();
        int m = arr[0].size();

        vector<vector<int>> all;

        for(int i=0; i<n; i++){
            vector<int> tall;
            for(int j=0; j<m; j++){
                set<int> temp;
                int ii = i;
                int jj = j;
                if(i+k-1>=n || j+k-1>=m) continue;
                int ans = 1e9;
                for(int ii=i; ii<i+k; ii++){
                    for(int jj=j; jj<j+k; jj++){
                        temp.insert(arr[ii][jj]);
                    }
                }
                vector<int> temper;
                for(int ek: temp) temper.push_back(ek); 
                for(int ii=0; ii<temper.size()-1; ii++){
                    ans = min(ans, abs(temper[ii+1]-temper[ii]));
                }
                if(ans == 1e9) ans = 0;
                tall.push_back(ans);
            }
            if(tall.empty()) continue;
            all.push_back(tall);
        }

        return all;

        
    }
};