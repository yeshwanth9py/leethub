// Last updated: 6/11/2026, 11:10:16 AM
class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        unordered_map<int, int> ump;
        set<int> all;
        for(int el: nums){
            ump[el]++;
            all.insert(el);
        }

        vector<int> arr;
        for(int el: all) arr.push_back(el);

        sort(arr.begin(), arr.end());

        int ax = -1;
        int ay = -1;
        
        for(int i=0; i<arr.size(); i++){
            for(int j=i+1; j<arr.size(); j++){
                if(ump[arr[i]] != ump[arr[j]]){
                    if(ax == -1 || ax>arr[i]){
                        ax = arr[i];
                        ay = arr[j];
                    }else if(ax == arr[i]){
                        ay = min(ay, arr[j]);
                    }
                }
            }
        }
        return {ax, ay};
        
        
    }
};