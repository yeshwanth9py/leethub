// Last updated: 6/11/2026, 11:14:32 AM
class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arr, int w, int m) {
        int n = arr.size();
        int ans = 0;
        unordered_map<int, int> mp;
        vector<int> remo(n, 0);
        for(int i=0; i<w; i++){
            mp[arr[i]]++;
            cout<<mp[arr[i]]<<" ";
            if(mp[arr[i]] > m){
                ans += 1;
                remo[i] = 1;
                mp[arr[i]] = m;
            }
        }
        
        int j = 0;
        if(remo[j] == 0){
            mp[arr[j]]--;
        }
        j++;
        for(int i=w; i<n; i++){
            mp[arr[i]]++;
            cout<<mp[arr[i]]<<" ";
            if(mp[arr[i]] > m){
                ans += 1;
                mp[arr[i]] = m;
                remo[i] = 1;
            }
            if(remo[j] == 0){
                mp[arr[j]]--;
            }
            j++;
        }

        return ans; 
    }
};





