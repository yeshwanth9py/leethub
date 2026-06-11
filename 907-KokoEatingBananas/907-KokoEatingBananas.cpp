// Last updated: 6/11/2026, 11:30:35 AM
#include<bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
    bool check(int x, vector<int>& piles, int h){
        ll ct = 0;
        for(int i=0; i<piles.size(); i++){
            ct += ceil(piles[i]/(1.0*x));
        }
        return ct<=h;
    }
    ll minEatingSpeed(vector<int>& piles, int h) {
        // int low = *min_element(piles.begin(), piles.end());
        ll low = 1;
        ll high = 1e9;

        cout<<low<<" "<<high<<endl;

        ll ans = -1;

        while(low<=high){
            ll mid = (low+high)/2;
            if(check(mid, piles, h)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        return ans;
    }
};