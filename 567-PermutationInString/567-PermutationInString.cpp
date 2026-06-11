// Last updated: 6/11/2026, 11:32:25 AM
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int i = 0;
        int j = -1;
        int n = s1.length();
        vector<int> freq(26, 0);
        int cnt1 = 0;

        for(int i=0; i<n; i++){
            freq[s1[i]-'a']++;
            if(freq[s1[i]-'a'] == 1){
                cnt1++;
            }
        }

        vector<int> freq2(26, 0);
        int cnt2 = 0;

        while(i<s2.length()){
            while(j+1<s2.length() && (j+1)-(i)+1<=n){
                j++;
                freq2[s2[j]-'a']++;
                if(freq2[s2[j]-'a'] == freq[s2[j]-'a']){
                    cnt2++;
                }
            }

            if(j-i+1==n){
                if(cnt1 == cnt2){
                    return 1;
                }
            }

            if(i>j){
                i++;
                j=i-1;
            }else{
                freq2[s2[i]-'a']--;
                if(freq2[s2[i]-'a']+1 == freq[s2[i]-'a']){
                    cnt2--;
                }
                i++;
            }
        }


        return 0;


    }
};