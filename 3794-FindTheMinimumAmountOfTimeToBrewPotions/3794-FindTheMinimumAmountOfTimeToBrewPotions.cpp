// Last updated: 6/11/2026, 11:15:45 AM
class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        vector<long long> curr(n, 0);
        vector<long long> prev(n, 0);
        long long prevcor = 0;

        long long st = 0;
        for(long long i=0; i<mana.size(); i++){
            st = prev[0];
            vector<long long> add(n, 0);
            long long prevcor = 0;
            for(long long j=0; j<skill.size(); j++){
                curr[j] = ((j-1>=0)?curr[j-1]:st) + mana[i]*skill[j];
                if(j+1<skill.size() && curr[j]<prev[j+1]){
                    prevcor = (prev[j+1] - curr[j]);
                    add[0] += prevcor;
                    add[j] -= prevcor; 
                    curr[j] = prev[j+1];
                }
            }
            for(long long j=0; j<skill.size(); j++){
                add[j] = ((j-1>=0)?add[j-1]:0) + add[j];
                curr[j] += add[j];
            }
           
            swap(prev, curr);
        }

        return prev[n-1];

    }
};