// Last updated: 6/11/2026, 11:16:42 AM
class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int , int> bump;
        int n = nums.size();
        int head = -1;
        int tail = 0;
        unordered_map<int , int> ump;
        while(tail<n){
            while(head+1<n && (head+1)-tail+1<=k){
                head++;
                ump[nums[head]]++;
            }

            if(head-tail+1==k){
                for(auto el: ump){
                    bump[el.first] += 1;
                }
            }

            if(tail>head){
                tail++;
                head = tail-1;
            }else{
                ump[nums[tail]]--;
                if(ump[nums[tail]]<=0){
                    ump.erase(nums[tail]);
                }
                tail++;
            }
        }
        int maxel = -1;
        for(auto el: bump){
            cout<<el.first<<" "<<el.second<<endl;
            if(el.second == 1){
                maxel = max(maxel, el.first);
            }
        }

        return maxel;
    }
};