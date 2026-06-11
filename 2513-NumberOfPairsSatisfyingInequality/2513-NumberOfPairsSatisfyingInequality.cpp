// Last updated: 6/11/2026, 11:22:09 AM
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template <class T>

using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        ordered_set<pair<long long, long long>> os; //storing pair to avoid duplicates
        long long ans = 0;
        long long n = nums1.size();
        for(long long i=0; i<n; i++){
            long long sch = nums1[i]-nums2[i]+diff;
            long long nosm = os.order_of_key({sch, 1e9}); //gives no of elems stricly smaller than sch

            if(nosm>0){
                ans += nosm;
            }

            long long store = nums1[i] - nums2[i];
            os.insert({store, i});
        }

        return ans;
    }
};