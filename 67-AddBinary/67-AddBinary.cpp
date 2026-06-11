// Last updated: 6/11/2026, 11:37:22 AM
class Solution {
public:
    string addBinary(string a, string b) {
        int c = 0;
        int i = a.size()-1;
        int j = b.size()-1;

        string ans = "";
        while(i>=0 && j>=0){
            int v1 = a[i]-'0';
            int v2 = b[j]-'0';
            int cur = v1+v2+c;
            if(cur == 3){
                ans.push_back('1');
                c = 1;
            }else if(cur==2){
                ans.push_back('0');
                c = 1;
            }else if(cur == 1){
                ans.push_back('1');
                c = 0;
            }else{
                ans.push_back('0');
                c=0;
            }
            i--;
            j--;
        }

        while(i>=0){
            int v1 = a[i]-'0';
            int cur = c+v1;
            if(cur == 2){
                ans.push_back('0');
                c = 1;
            }else if(cur == 1){
                ans.push_back('1');
                c = 0;
            }else{
                ans.push_back('0');
                c=0;
            }
            i--;
        }

        while(j>=0){
            int v1 = b[j]-'0';
            int cur = c+v1;
            if(cur == 2){
                ans.push_back('0');
                c = 1;
            }else if(cur == 1){
                ans.push_back('1');
                c = 0;
            }else{
                ans.push_back('0');
                c=0;
            }
            j--;
        }
        if(c){
            ans.push_back('1');
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};