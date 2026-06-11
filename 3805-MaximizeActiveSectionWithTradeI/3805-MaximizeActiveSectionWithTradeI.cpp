// Last updated: 6/11/2026, 11:15:38 AM


class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int origOnes = 0;
        for (char c : s) {
            if(c == '1') origOnes++;
        }
       
        int best = origOnes;
        
        
        for (int i = 0; i < n; ) {
            if (s[i] == '1') {
                int start = i;
                while (i < n && s[i] == '1') {
                    i++;
                }
                int end = i - 1; 
                
                
                int left = start;
                while (left > 0 && s[left - 1] == '0') {
                    left--;
                }
               
                int right = end;
                while (right < n - 1 && s[right + 1] == '0') {
                    right++;
                }
                
                
                if (s[left] == '0' && s[right] == '0') {
                    int len = right - left + 1;
                    int onesInCandidate = (end - start + 1);
                    int gain = len - onesInCandidate; 
                    best = max(best, origOnes + gain);
                }
            } else {
                i++;
            }
        }
        
        return best;
    }
};
