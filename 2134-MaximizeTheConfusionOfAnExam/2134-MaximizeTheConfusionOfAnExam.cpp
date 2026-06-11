// Last updated: 6/11/2026, 11:24:46 AM
class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int sz = s.size();
        int l = 0;
        int cnt = 0;
        int res = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == 'T'){
                cnt++;
            }
            while(cnt>k){
                if(s[l] == 'T'){
                    cnt--;
                }
                l++;
            }
            res = max(res, i-l+1);
        }

        cnt = 0;

        l = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == 'F'){
                cnt++;
            }
            while(cnt>k){
                if(s[l] == 'F'){
                    cnt--;
                }
                l++;
            }

            res = max(res, i-l+1);
        }

        return res;




    }
};