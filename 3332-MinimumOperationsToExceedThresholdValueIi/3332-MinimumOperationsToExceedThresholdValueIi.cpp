// Last updated: 6/11/2026, 11:18:48 AM
using ll = long long;
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for(int el: nums){
            pq.push(el);
        }
        int op = 0;
        while(pq.size()>=2){
            ll l1 = pq.top(); pq.pop();
            ll l2 = pq.top(); pq.pop();
            if(l1>=k && l2>=k){
                break;
            }
            op++;
            pq.push(min(l1, l2)*2+max(l1, l2));
        }
        return op;


    }
};