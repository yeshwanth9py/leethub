// Last updated: 6/11/2026, 11:18:20 AM
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        map<int, int> ump;
        int last = 1;
        int free = 0;
        int tot = 0;
        ump[1] = 0;
        ump[days+1] = 0;
        for(auto el: meetings){
            ump[el[0]]++;
            ump[el[1]+1]--;
        }
        
        for(auto el: ump){
            int cday = el.first;
            // cout<<cday<<" "<<last<<":- "<<free<<" "<<(cday-last)<<endl;
            if(free == 0){
                tot += cday-last;
            }
            free += el.second;
            last = cday;
        }

        return tot;
    }
};