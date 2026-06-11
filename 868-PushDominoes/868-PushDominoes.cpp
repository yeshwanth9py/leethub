// Last updated: 6/11/2026, 11:30:50 AM
class Solution {
public:
    string pushDominoes(string s) {
        int i = 0;
        char prv = '.';
        while(i<s.size()){
            if(s[i] == '.'){
                int j = i;
                while(j<s.size() && s[j] == '.'){
                    j++;
                }
                if(j == s.size()){
                    if(prv == 'L' || prv  == '.'){
                        i = j;
                    }else{
                        j = i;
                        while(j<s.size() && s[j] == '.'){
                            s[j] = 'R';
                            j++;
                        }
                        i = j;
                    }
                }else{
                    if(s[j] == 'R'){
                        if(prv == 'R'){
                            int cur = i;
                            while(cur<j){
                                s[cur] = 'R';
                                cur++;
                            }
                            i = j;
                        }else{
                            i = j;
                        }
                    }else{
                        if(prv == 'L' || prv == '.'){
                            int cur = j;
                            while(cur>=i){
                                s[cur] = 'L';
                                cur--;
                            }
                            i = j;
                        }else{
                            int l = i;
                            int r = j-1;
                            while(l<r){
                                s[l] = 'R';
                                s[r] = 'L';
                                l++;
                                r--;
                            }
                            i = j;
                        }
                    }
                }
            }else{
                prv = s[i];
                i++;
            }
        }

        return s;
    }
};