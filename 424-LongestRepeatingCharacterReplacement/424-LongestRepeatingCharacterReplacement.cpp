// Last updated: 6/11/2026, 11:33:10 AM
class Solution {
public:
    bool caniinclude(char ch, unordered_map<char, int> &ump, int rem){
        int maxf = 1;
        char maxch = ch;
        ump[maxch]++;


        int totf = 0;
        for(auto el: ump){
            if(el.second>maxf){
                maxf = el.second;
                maxch = el.first;
            }
            totf += el.second;
        }

        ump[ch]--;

        if(totf-maxf <= rem){
            return 1;
        }

        return 0;
    }

    int characterReplacement(string s, int k) {
        int i=0;
        int j=-1;
        int n = s.size();
        unordered_map<char, int> ump;

        int ans = 0;
        int rem = k;
        while(i<n){
            while(j+1<n && caniinclude(s[j+1], ump, rem)){
                j++;
                ump[s[j]]++;
            }

            if(j-i+1>ans){
                ans = j-i+1;
            }
            
            if(i>j){
                i++;
                j=i-1;
            }else{
                ump[s[i]]--;
                i = i+1;
            }
        }

        return ans;
    }
};