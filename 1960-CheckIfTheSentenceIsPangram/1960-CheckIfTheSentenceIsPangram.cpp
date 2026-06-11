// Last updated: 6/11/2026, 11:25:43 AM
class Solution {
public:
    bool checkIfPangram(string sentence) {
        int arr[26] = {0};
        int cnt = 0;
        for(char ch: sentence){
            if(arr[ch-'a'] == 0){
                cnt++;
                arr[ch-'a']++;
            }
        }

        return cnt==26;



    }
};