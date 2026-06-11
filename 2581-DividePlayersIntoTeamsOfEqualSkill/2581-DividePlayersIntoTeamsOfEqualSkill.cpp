// Last updated: 6/11/2026, 11:21:55 AM
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        map<long long, int> mp;

        int n = skill.size();

        long long ts = (accumulate(skill.begin(), skill.end(), 0))/(n/2);

        int p = 0;

        long long ans=0;

        for(int i=0; i<n; i++){
            long long el = skill[i];
            if(mp[ts-el]>0){
                mp[ts-el] -= 1;
                if(mp[ts-el]<0){
                    mp[ts-el] =0;
                }
                ans += (ts-el)*(el);
                p +=1;
            } else {
                mp[el] += 1; 
            }
        }

        if(p == (n/2)){
            return ans;
        } else{
            return -1;
        }
    }
};