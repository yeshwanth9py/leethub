// Last updated: 6/11/2026, 11:22:24 AM
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<pair<int, int>> seg;
        for(auto vec: shifts){
            int st = vec[0];
            int en = vec[1];
            int va = vec[2];
            if(va>0){
                seg.push_back({st,  1});
                seg.push_back({en+1,-1});
            }else{
                seg.push_back({st, -1});
                seg.push_back({en+1, 1});
            }
        }

        sort(seg.begin(), seg.end(), [&](pair<int, int> &a, pair<int, int> &b){
            if(a.first != b.first){
                return a.first < b.first;
            }
            return a.second > b.second;
        });

        int cnt = 0;
        // removed ind entirely—no other changes here
        for(int i = 0; i + 1 < seg.size(); i++){
            cnt += seg[i].second;

            if(seg[i].first != seg[i+1].first){
                // ◀︎ replaced your single-char ind++ block with this ◀︎
                int L = max(0, seg[i].first);
                int R = min((int)s.size(), seg[i+1].first);
                for(int pos = L; pos < R; pos++){
                    if(cnt >= 0){
                        s[pos] = char((s[pos] - 'a' + cnt) % 26 + 'a');
                    } else {
                        int tempo = (cnt % 26 + 26) % 26;
                        s[pos] = char((s[pos] - 'a' + tempo) % 26 + 'a');
                    }
                }
            }
        }

        return s;
    }
};
