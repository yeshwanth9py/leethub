// Last updated: 6/11/2026, 11:18:23 AM
class Solution {
public:
    int k;
    map<vector<int>, int> mp;
    int rec(int ind, int jump, int back){
        if(ind<0){
            return 0;
        }

        if(ind > k+1){
            return 0;
        }

        if(mp.find({ind, jump, back})!=mp.end()){
            return mp[{ind, jump, back}];
        }

        int ways = 0;
        if(ind == k){
            ways = 1;
        }

        if(back && ind!=0){
            ways += rec(ind-1, jump, 0);
        }
        ways += rec(ind+pow(2, jump), jump+1, 1);

        return mp[{ind, jump, back}] = ways;
    }

    int waysToReachStair(int k) {
        this->k = k;
        return rec(1, 0, 1);
    }
};