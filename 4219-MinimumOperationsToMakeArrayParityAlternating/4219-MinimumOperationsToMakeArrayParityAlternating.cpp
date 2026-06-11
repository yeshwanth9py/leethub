// Last updated: 6/11/2026, 11:10:27 AM
class Solution {
public:
    vector<int> makeParityAlternating(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return {0, 0};
        unordered_map<int, int> fre;
        for(int el: nums){
            fre[el]++;
        }
        
        int ans = *max_element(nums.begin(), nums.end());

        int mx = ans;
        int mn = *min_element(nums.begin(), nums.end());
        ans -= mn;

        //o e
        int fmax = fre[mx];
        int fmin = fre[mn];
        
        int prev = 0;
        int op1 = 0;
        int ans1 = ans;
        for(int i=0; i<n; i++){
            if(prev == 1){
                if(abs(nums[i])%2 == 1){
                    if(nums[i] == mx){
                        fmax--;
                    }else if(nums[i] == mn){
                        fmin--;
                    }
                    op1++;
                }
            }else{
                if(abs(nums[i])%2 == 0){
                    if(nums[i] == mx){
                        fmax--;
                    }else if(nums[i] == mn){
                        fmin--;
                    }
                    op1++;
                }
            }
            prev = !prev;
        }

        if(fmax == 0){
            ans1-=1;
        }
        if(fmin == 0){
            ans1 -= 1;
        }

        prev = 1;
        int op2 = 0;
        int ans2 = ans;
        fmax = fre[mx];
        fmin = fre[mn];
        
        for(int i=0; i<n; i++){
            if(prev == 1){
                if(abs(nums[i])%2 == 1){
                    if(nums[i] == mx){
                        fmax--;
                    }else if(nums[i] == mn){
                        fmin--;
                    }
                    op2++;
                }
            }else{
                if(abs(nums[i])%2 == 0){
                    if(nums[i] == mx){
                        fmax--;
                    }else if(nums[i] == mn){
                        fmin--;
                    }
                    op2++;
                }
            }
            prev = !prev;
        }

        if(fmax == 0){
            ans2 -= 1;
        }
        if(fmin == 0){
            ans2 -= 1;
        }

        if(mx == mn){
            ans1 = ans2 = 1;
        }
        
        if(op1<op2){
            return {op1, ans1};
        }else if(op2<op1){
            return {op2, ans2};
        }else{
            return {op1, min(ans1, ans2)};
        }
 

        
    }
};