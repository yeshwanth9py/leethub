// Last updated: 6/11/2026, 11:17:48 AM

using ll = long long;
class Solution {
public:
    long long atleast(string word, ll k){
        unordered_map<char, ll> vowels = {{'a',0}, {'e',0}, {'i',0}, {'o',0}, {'u',0}};
        unordered_map<char, ll> consonants;

        ll n = word.length();
        ll i = 0;
        ll j = -1;

        ll ctn = 0;
        ll vtn= 0;

        ll ans = 0;
        while(i<n){
            while(j+1<n && (ctn<k || vtn<5) ){
                j++;
                if(vowels.find(word[j])!=vowels.end()){
                    vowels[word[j]]++;
                    if(vowels[word[j]] == 1){
                        vtn++;
                    }
                }else{
                    ctn++;
                }
            }

            if(vtn == 5 && ctn >=k){
                ans += (n-j);
            }

            if(i>j){
                i++;
                j=i-1;
            }else{
                if(vowels.find(word[i])!=vowels.end()){
                    vowels[word[i]]--;
                    if(vowels[word[i]] == 0){
                        vtn--;
                    }
                }else{
                    ctn--;
                }
                i++;
            }
        }
            return ans;
    }
    long long countOfSubstrings(string word, int k) {
        return atleast(word, k)-atleast(word, k+1);
    }
};