// Last updated: 6/11/2026, 11:18:18 AM
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> ans;
        
        unordered_map<int, int> cols;
        unordered_map<int, int> ball;
        int cnt = 0;

        for(auto sq: queries){
            int b = sq[0];
            int c = sq[1];

            if(ball.find(b)!=ball.end() && ball[b]>0){
                cols[ball[b]]--;
                if(cols[ball[b]]<=0){
                    cnt--;
                }
            }

            ball[b] = c;
            cols[ball[b]]++;
            if(cols[ball[b]]==1){
                cnt++;
            }

            ans.push_back(cnt);
        }

        return ans;
    }
};