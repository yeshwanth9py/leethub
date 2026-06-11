// Last updated: 6/11/2026, 11:17:44 AM
// class Solution {
// public:
//     vector<long long> findXSum(vector<long long>& nums, long long k, long long x) {
        
//     }
// };

struct mytopk{
    multiset<pair<long long, long long>, greater<pair<long long, long long>>> ms1;
    multiset<pair<long long, long long>> ms2;
    long long sum = 0;
    long long k;
    mytopk(long long k){
        // ms1.erase();
        // ms2.erase();
        this->k = k;
        sum = 0;
    }

    void balance(){
        while(ms1.size()<k && ms2.size()>0){
            auto it = ms2.rbegin();
            ms1.insert(*it);
            sum += (((*it).first) * ((*it).second));
            ms2.erase(ms2.find(*it));
        }

        while(ms1.size()>k){
            auto it = ms1.rbegin();
            ms2.insert(*it);
            sum -= (((*it).first) * ((*it).second));
            ms1.erase(ms1.find(*it));
        }
    }

    void insert(long long el, long long freq){
        ms1.insert({freq, el});
        sum += (freq*el);
        balance();
    }

    void remove(long long el, long long freq){
        if(ms1.find({freq, el})!=ms1.end()){
            ms1.erase(ms1.find({freq, el}));
            sum -= freq*el;
        }else if(ms2.find({freq, el})!=ms2.end()){
            ms2.erase(ms2.find({freq, el}));
        }
        balance();
    }

    long long gettopks(){
        return sum;
    }
};

class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        unordered_map<long long, long long> ump;
        long long n = nums.size();
        mytopk ds(x);

        for(long long i=0; i<k; i++){
            ump[nums[i]]++;
            if(ump[nums[i]]>1){
                ds.remove(nums[i], ump[nums[i]]-1);
            }
            ds.insert(nums[i], ump[nums[i]]);
        }
        
        vector<long long> ans;
        ans.push_back(ds.gettopks());

        long long j=0;
        for(long long i=k; i<n; i++){
            ump[nums[j]]--;
            ds.remove(nums[j], ump[nums[j]]+1);
            if(ump[nums[j]]>0){
                ds.insert(nums[j], ump[nums[j]]);
            }
            j++;

            ump[nums[i]]++;
            if(ump[nums[i]]>1) ds.remove(nums[i], ump[nums[i]]-1);

            if(ump[nums[i]]>0){
                ds.insert(nums[i], ump[nums[i]]);
            }

            ans.push_back(ds.gettopks());
        }

        return ans;
    }
};