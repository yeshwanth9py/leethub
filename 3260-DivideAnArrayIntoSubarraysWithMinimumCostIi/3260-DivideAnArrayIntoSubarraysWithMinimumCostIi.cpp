// Last updated: 6/11/2026, 11:19:04 AM

#define ll long long
ll k;
struct mystruct{
    multiset<ll> ms1;
    multiset<ll> ms2;
    ll topksum = 0;
    void insert(ll el){
        if(ms1.size()<k){
            ms1.insert(el);
            topksum += el;
        }else{
            ll ls = *(ms1.rbegin());
            if(ls>el){
                ms1.erase(ms1.find(ls));
                topksum -= ls;
                ms2.insert(ls);
                ms1.insert(el);
                topksum += el;
            }else{
                ms2.insert(el);
            }
        }

        // prller();
    }

    void erase(ll el){
        if(ms2.find(el) != ms2.end()){
            ms2.erase(ms2.find(el));
        }else if(ms1.find(el) != ms1.end()){
            ms1.erase(ms1.find(el));
            topksum -= el;
            if(ms2.size()==0) return;
            ll fs = *(ms2.begin());
            ms1.insert(fs);
            topksum += fs;
            ms2.erase(ms2.find(fs));
        }
        // prller();
    }

    void printer(){
        auto it = ms1.begin();
        while(it != ms1.end()){
            cout<<*(it)<<" ";
            it++;
        }
        cout<<endl;
    }

    ll getsum(){
        return topksum;
    }
};


class Solution {
public:
    long long minimumCost(vector<int>& nums, int K, int dist) {
        ll ans = 1e18;
        int n = nums.size();
        K--;
        k = K;
        mystruct mys;
        ll cur = nums[0];
        for(ll i=1; i<=min(dist+1, n-1); i++){
            mys.insert(nums[i]);
        }
        ans = cur+mys.getsum();
        // cout<<ans<<" "<<endl;

        mys.erase(nums[1]);
        ll l = min(dist+1, n-1);
        // cout<<"l: "<<l<<endl;
        // mys.erase(nums[l]);
        l++;
        for(ll i=2; i<n; i++){
            if(l>=n) break;
            mys.insert(nums[l]);
            ans = min(ans, cur+mys.getsum());
            // cout<<ans<<" "<<endl;
            mys.erase(nums[i]);
            // mys.erase(nums[l]);
            l++;
        }

        return ans;
    }
};