// Last updated: 6/11/2026, 11:14:35 AM
class Solution {
public:
    vector<int> div;
    vector<int> ans;
    int maxd = 1e9;
    void bruteforce(int num, int rem, vector<int> &arr){
        if(rem == 0){
            arr.push_back(num);
            int mn = *min_element(arr.begin(), arr.end());
            int mx = *max_element(arr.begin(), arr.end());
            
            if((mx-mn)<maxd){
                maxd = mx-mn;
                ans = arr;
            }
            arr.pop_back();
            return;
        }

        for(int i=0; i<div.size(); i++){
            if(num%div[i] == 0){
                arr.push_back(div[i]);
                bruteforce(num/div[i], rem-1, arr);
                arr.pop_back();
            }
        }
    }

    vector<int> minDifference(int n, int k) {
        vector<int> arr;
        for(int i=1; i*i<=n; i++){
            if(n%i == 0){
                int d1 = i;
                div.push_back(d1);
                int d2 = n/i;
                if(d2 != d1){
                    div.push_back(d2);
                }
            }
        }
        sort(div.begin(), div.end());
        maxd = 1e9;
        bruteforce(n, k-1, arr);
        return ans;
    }
};