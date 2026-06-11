// Last updated: 6/11/2026, 11:14:38 AM
class Solution {
public:
    int minTime(string s, vector<int>& order, int k) {
        multiset<long long> ms;
        long long n = s.length();
        ms.insert(-1);
        ms.insert(n);
        long long cnt = 0;
        long long tim = 0;
        for(long long el: order){
            auto idx = ms.upper_bound(el);

            long long nidx = *idx;
            idx--;
            long long pidx = *(idx);
            long long added = (el-pidx)*(nidx-el);
            cnt += added;
            cout<<added<<" ";
            if(cnt>=k){
                return tim;
            }
            tim++;
            ms.insert(el);
        }
        return -1;
    }
};