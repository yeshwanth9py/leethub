// Last updated: 6/11/2026, 11:32:39 AM
class Solution {
public:
    string reverseStr(string s, int k) {
        string ans = "";
        string temp = "";

        bool flag = 1;
        int t = -1;
        for(int i=0; ; i=i+k){
            if(i<s.size()){
                if(flag == 1){
                    temp = s.substr(i, k);
                    reverse(temp.begin(), temp.end());
                    ans += temp;
                    flag = !flag;
                }else{
                    temp = s.substr(i, k);
                    ans += temp;
                    flag = !flag;
                }
                t = i+k;
            }else{
                if(flag){
                    // temp = "";
                    while(t<s.size()){
                        ans = s[i] + ans;
                        t++;
                    }

                }else{
                    while(t<s.size()){
                        ans += s[i];
                        t++;
                    }
                }
                break;
            }
        }

        return ans;

    }
};