// Last updated: 6/11/2026, 11:16:28 AM
#define pb push_back
class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        startTime.push_back(eventTime);
        vector<int> allgaps;
        int prev = 0;
        int n = startTime.size();
        for(int i=0; i<n; i++){
            allgaps.pb(startTime[i]-prev);
            if(i == startTime.size()-1) break;
            prev = endTime[i];
        }
        k++;

        int curgp = 0;
        int maxcurgp = 0;
        for(int i=0; i<allgaps.size(); i++){
            curgp += allgaps[i];
            maxcurgp = max(maxcurgp, curgp);
            if(i-k+1>=0){
                curgp -= allgaps[i-k+1];
            }
        }

        return maxcurgp;

    }
};