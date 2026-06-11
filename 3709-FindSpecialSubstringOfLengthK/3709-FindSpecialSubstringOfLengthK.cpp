// Last updated: 6/11/2026, 11:16:40 AM
class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int tail = 0;
        int head = -1;
        int n = s.length();
        while(tail<n){
            while(head+1<n && s[head+1] == s[tail]){
                head++;
            }
            if(head-tail+1 == k){
                return true;
            }

            if(tail>head){
                tail++;
                head = tail-1;
            }else{
                tail = head+1;
            }
        }

        return false;
    }

};