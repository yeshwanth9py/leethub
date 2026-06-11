// Last updated: 6/11/2026, 11:25:10 AM
#define f first
#define s second
class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        vector<pair<pair<long long, long long>, pair<long long, long long>>> seg;
        for(long long i=0; i<segments.size(); i++){
            vector<int> vec = segments[i];
            long long s = vec[0];
            long long e = vec[1];
            long long v = vec[2];
            seg.push_back({{s, 1},{i, v}});
            seg.push_back({{e, -1},{i, -v}});
        }
        sort(seg.begin(), seg.end());
        vector<vector<long long>> ans;
        long long cnt = 0;
        for(int i=0; i<seg.size()-1; i++){
            cnt += seg[i].s.s;
            if(cnt == 0 || seg[i].f.f == seg[i+1].f.f) continue;
            ans.push_back({seg[i].f.f, seg[i+1].f.f, cnt});
        }
        return ans;
    }
};