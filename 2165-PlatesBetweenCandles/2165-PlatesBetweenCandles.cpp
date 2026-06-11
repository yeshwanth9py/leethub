// Last updated: 6/11/2026, 11:24:24 AM
class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> cnt(n, 0);
        if(s[0] == '*'){
            cnt[0] = 1;
        }
        for(int i=1; i<n; i++){
            if(s[i] == '*'){
                cnt[i] = 1 + cnt[i-1];
            }else{
                cnt[i] = cnt[i-1];
            }
        }

        vector<int> left_pl(n, -1);
        vector<int> right_pl(n, -1);

        if(s[0] == '|'){
            left_pl[0] = 0;
        }

        if(s[n-1] == '|'){
            right_pl[n-1] = n-1;
        }

        for(int i=1; i<n; i++){
            if(s[i] == '|'){
                left_pl[i] = i;
            }else{
                left_pl[i] = left_pl[i-1];
            }
        }

        for(int i=n-2; i>=0; i--){
            if(s[i] == '|'){
                right_pl[i] = i;
            }else{
                right_pl[i] = right_pl[i+1];
            }
        }

        vector<int> ans;

        for(int i=0; i<queries.size(); i++){
            int lq = queries[i][0];
            int rq = queries[i][1];

            int lp = right_pl[lq];
            int rp = left_pl[rq];

            if(lp!=-1 && rp!=-1 && lp<=rp){
                ans.push_back(cnt[rp]-cnt[lp]);
            }else{
                ans.push_back(0);
            }
        }

        return ans;


    }
};