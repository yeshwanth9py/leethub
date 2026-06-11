// Last updated: 6/11/2026, 11:11:20 AM
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, multiset<int>> ump;
        
        for(int el: nums){
            int cap = el%3;
            if(cap == 0){
                ump[0].insert(el);
            }else if(cap == 1){
                ump[1].insert(el);
            }else{
                ump[2].insert(el);
            }
        }
        int maxs = 0;
        if(ump[0].size()>=1 && ump[1].size()>=1 && ump[2].size()>=1){
            int a = *ump[0].rbegin() + *ump[1].rbegin() + *ump[2].rbegin();
            maxs = max(maxs, a);
        }

        if(ump[2].size()>=3){
            int b1 = *(ump[2].rbegin());
            ump[2].erase(ump[2].find(b1));
            int b2 = *(ump[2].rbegin());
            ump[2].erase(ump[2].find(b2));
            int b3 = *(ump[2].rbegin());
            ump[2].erase(ump[2].find(b3));

            int cs = b1+b2+b3;
            maxs = max(maxs, cs);
        }

        if(ump[1].size()>=3){
            int b1 = *(ump[1].rbegin());
            ump[1].erase(ump[1].find(b1));
            int b2 = *(ump[1].rbegin());
            ump[1].erase(ump[1].find(b2));
            int b3 = *(ump[1].rbegin());
            ump[1].erase(ump[1].find(b3));

            int cs = b1+b2+b3;
            maxs = max(maxs, cs);
        }

        if(ump[0].size()>=3){
            int b1 = *(ump[0].rbegin());
            ump[0].erase(ump[0].find(b1));
            int b2 = *(ump[0].rbegin());
            ump[0].erase(ump[0].find(b2));
            int b3 = *(ump[0].rbegin());
            ump[0].erase(ump[0].find(b3));

            int cs = b1+b2+b3;
            maxs = max(maxs, cs);
        }
        
        return maxs;
    }
};