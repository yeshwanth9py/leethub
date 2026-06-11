// Last updated: 6/11/2026, 11:18:12 AM
class Solution {
public:
    string clearDigits(string s) {
        int n = s.size();
        int leftd[n];
        leftd[0] = -1;

        for(int i=1; i<n; i++){
            if(s[i-1]>='a' && s[i-1]<='z'){
                leftd[i] = i-1;
            }else{
                leftd[i] = leftd[i-1];
            }
        }


        vector<int> mark(n, 1);

        for(int i=0; i<n; i++){
            if(s[i]>='0' && s[i]<='9'){
                while(leftd[i] != -1 && mark[leftd[i]] == 0){
                    leftd[i] = leftd[leftd[i]];
                }
                if(leftd[i]!=-1 && mark[leftd[i]] == 1){
                    mark[leftd[i]] = 0;
                }
                mark[i] = 0;
            }
        }

        string ans = "";
        for(int i=0; i<n; i++){
            if(mark[i]){
                ans += s[i];
            }
        }

        return ans;

        
    }
};