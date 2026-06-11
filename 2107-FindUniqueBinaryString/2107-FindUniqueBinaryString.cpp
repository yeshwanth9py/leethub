// Last updated: 6/11/2026, 11:25:00 AM
class Solution {
public:
    int getnum(string &s){
        int numb = 0;
        int n = s.size();
        for(int i=n-1; i>=0; i--){
            if(s[n-i-1] == '1'){
                numb |= (1LL<<i);
            }
        }
        return numb;
    }

    string convert(int numb, int n){
        string ans = "";
        for(int i=0; i<n; i++){
            if(numb&(1LL<<i)){
                ans.push_back('1');
            }else{
                ans.push_back('0');
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        vector<int> vis(1LL<<n, 0);
        for(string s: nums){
            int nu = getnum(s);
            vis[nu] = 1;
        }

        for(int i=0; i<(1LL<<n); i++){
            if(vis[i] == 0){
                string cur = convert(i, n);
                return cur;
            }
        }

        return "";

        

    }
};