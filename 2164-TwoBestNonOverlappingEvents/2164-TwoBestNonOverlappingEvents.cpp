// Last updated: 6/11/2026, 11:24:25 AM
struct Comp{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const{
        if(a.first!=b.first){
            return a.first<b.first;
        }else{
            return a.second>b.second;
        }
    }
};

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& arr) {
        int n = arr.size();
        int maxv = 0;
        sort(arr.begin(), arr.end());

        multiset<pair<int, int>, Comp> avail;

        int prevmx = -1;
        for(int i=n-1; i>=0; i--){
            maxv = max(maxv, arr[i][2]);
            auto it = avail.lower_bound({arr[i][1]+1, INT_MAX});
            if(it!=avail.end()){
                maxv = max(maxv, (*it).second + arr[i][2]);
            }
            
            int curmx = max(prevmx, arr[i][2]);
            avail.insert({arr[i][0], curmx});
            prevmx = curmx;
        }

        return maxv;
    }
};