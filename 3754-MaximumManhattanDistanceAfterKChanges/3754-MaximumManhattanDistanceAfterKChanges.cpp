// Last updated: 6/11/2026, 11:16:18 AM
class Solution {
public:
    int maxDistance(string s, int kk) {
        int no = 0;
        int so = 0;
        int ea = 0;
        int we = 0;


        int maxans = 0;

        for(int i=0; i<s.length(); i++){
            if(s[i] == 'N'){
                no++;
            }else if(s[i] == 'S'){
                so++;
            }else if(s[i] == 'E'){
                ea++;
            }else{
                we++;
            }
            int ans = 0;
            int k = kk;

            if(max(no, so)>max(ea, we)){
                ans += max(no, so)+min(k, min(no, so));
                ans -= (min(no, so) - min(k, min(no, so)));
                k -= min(k, min(no, so));

                ans += max(ea, we)+min(k, min(ea, we));
                ans -= (min(ea, we)-min(k, min(ea, we)));
                k -= min(k, min(ea, we));

            }else if(max(ea, we)>max(no, so)){
                ans += max(ea, we)+min(k, min(ea, we));
                ans -= (min(ea, we)-min(k, min(ea, we)));
                k -= min(k, min(ea, we));

                ans += max(no, so)+min(k, min(no, so));
                ans -= (min(no, so) - min(k, min(no, so)));
                k -= min(k, min(no, so)); 
            }else{
                if(min(no, so)>=min(ea, we)){
                    ans += max(no, so)+min(k, min(no, so));
                    ans -= (min(no, so) - min(k, min(no, so)));
                    k -= min(k, min(no, so));

                    ans += max(ea, we)+min(k, min(ea, we));
                    ans -= (min(ea, we)-min(k, min(ea, we)));
                    k -= min(k, min(ea, we));
                }else if(min(ea, we)>min(no, so)){
                    ans += max(ea, we)+min(k, min(ea, we));
                    ans -= (min(ea, we)-min(k, min(ea, we)));
                    k -= min(k, min(ea, we));

                    ans += max(no, so)+min(k, min(no, so));
                    ans -= (min(no, so) - min(k, min(no, so)));
                    k -= min(k, min(no, so));
                }
            }

            maxans = max(maxans, ans);
        }

        return maxans;

    }
};