// Last updated: 6/11/2026, 11:16:17 AM

using ll = long long;
class Solution {
public:
    ll my_lower_bound(vector<pair<ll, ll>> &vec, ll val){
        ll lo = 0;
        ll hi = vec.size()-1;
        int ans = -1;
        while(lo<=hi){
            ll mid = (lo+hi)/2;
            if(vec[mid].first == val){
                ans = mid;
                hi = mid-1;
            }else if(vec[mid].first>val){
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }

        return ans;
    } 
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<ll, ll>> vec;
        ll n = nums1.size();
        for(ll i=0; i<nums1.size(); i++){
            vec.push_back({nums1[i], nums2[i]});
        }

        sort(vec.begin(), vec.end());
        for(auto el: vec){
            cout<<el.first<<" "<<el.second<<", ";
        }
        cout<<endl;

        vector<ll> maxksum(n, 0);
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        ll cursum = 0;
        for(ll i=0; i<n; i++){
            pq.push(vec[i].second);
            cursum += vec[i].second;
            if(pq.size()>k){
                ll elp = pq.top();
                pq.pop();
                cursum -= elp;
            }
            maxksum[i] = cursum; 
        }
        
        vector<ll> ans;

        for(ll i=0; i<n; i++){
            ll elem = my_lower_bound(vec, nums1[i]);
            if(elem == 0){
                ans.push_back(0);
            }else{
                ans.push_back(maxksum[elem-1]);
            }
        }

        return ans;
        
    }
};