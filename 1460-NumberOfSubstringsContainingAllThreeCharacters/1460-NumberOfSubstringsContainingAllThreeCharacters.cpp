// Last updated: 6/11/2026, 11:28:01 AM
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int head = -1;
        int tail = 0;

        int a = 0;
        int b = 0;
        int c = 0;

        int tot = 0;

        while(tail<n){
            while(head+1<n && (a==0 || b==0 || c==0)){
                head++;
                if(s[head] == 'a'){
                    a++;
                }else if(s[head] == 'b'){
                    b++;
                }else{
                    c++;
                }
            }
            if(a>0 && b>0 && c>0){
                tot += n-head;
            }

            if(tail>head){
                tail++;
                head = tail-1;
            }else{
                if(s[tail] == 'a'){
                    a--;
                }else if(s[tail] == 'b'){
                    b--;
                }else{
                    c--;
                }
                tail++;
            }

        }

        return tot;
    }
};