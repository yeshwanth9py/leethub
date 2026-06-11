// Last updated: 6/11/2026, 11:31:15 AM
class Solution {
public:
    int numRabbits(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> ump;
        for(int i=0; i<n; i++){
            ump[nums[i]]++;
        }

        int ans = 0;
        for(auto el: ump){
            if(el.first == 0){
                ans += (el.second);
            }
            else if(el.first>=el.second){
                ans += (el.first+1);
            }else{
                // cout<<el.second<<" "<<el.first<<" "<<ceil(el.second/(el.first+1.00))<<" ";
                int temp = (ceil(el.second/(el.first+1.00)));
                // cout<<"temp"<<temp<<" ";
                temp = temp*(el.first+1.00);
                // cout<<"temp"<<temp<<" ";
                ans += temp;
            }
        }
        return ans;

    }
};