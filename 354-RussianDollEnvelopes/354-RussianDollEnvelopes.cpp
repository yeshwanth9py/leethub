// Last updated: 6/11/2026, 11:33:37 AM
int custom_bin_sch(vector<vector<int>> &tail, vector<int> &dol){
    int lo = 0;
    int hi = tail.size()-1;
    int ans = -1;
    
    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(tail[mid][1] >= dol[1]){
            ans = mid;
            hi = mid-1;
        }else{
            lo = mid+1;
        }
    }
    
    return ans;
}


int longest_inc_sub(vector<vector<int>> &dolls){
    vector<vector<int>> tail;
    // unordered_map<int, int> ump;  //pos -> len
    cout<<endl;
    for(int i=0; i<dolls.size(); i++){
        if((tail.empty()) || (tail.back()[1]<dolls[i][1])){
            tail.push_back(dolls[i]);
            cout<<tail.size()-1<<" ";
            // ump[tail.size()-1]++;
        }else{
            int idx = custom_bin_sch(tail, dolls[i]);
            cout<<idx<<" ";
            if(idx == -1) continue;
            tail[idx] = dolls[i];
            // ump[idx]++;
        }
    }
    
    return tail.size();
    // int maxreq = 0;
    // for(auto el: ump){
    //     maxreq = max(maxreq, ump[el.first]);
    // }
    
    // return maxreq;
    
}

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& dolls) {
        sort(dolls.begin(), dolls.end(), [&](vector<int> &a, vector<int> &b){
            if(a[0]!=b[0]) return a[0]<b[0];
            return a[1]>b[1];
        });
        for(auto el: dolls){
            cout<<el[0]<<" "<<el[1]<<", ";
        }
        return longest_inc_sub(dolls);
    }
};


