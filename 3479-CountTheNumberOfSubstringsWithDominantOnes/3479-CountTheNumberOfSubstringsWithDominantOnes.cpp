// Last updated: 6/11/2026, 11:18:01 AM
class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> zpos;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '1') continue;
            zpos.push_back(i);
        }

        zpos.push_back(s.size());

        int n = s.size();

        int ans = 0;
        for(int i=0; i<n; i++){
            int no0 = 0;
            int no1 = 0;

            if(s[i] == '0'){
                no0++;
            }else{
                no1++;
            }
            if(no1 == 1) ans++;

            auto it = upper_bound(zpos.begin(), zpos.end(), i);
            
            int ind = it-zpos.begin();
            // cout<<"ni "<<ind<<" "/;
            int prev = i;
            while(ind<zpos.size()){
                int btwo = zpos[ind]-prev-1;
                if(no0*no0<=no1){
                    ans += btwo;
                    no1 += btwo;
                }else{
                    no1 += btwo;
                    if(no0*no0<=no1){
                        ans += (no1-(no0*no0)+1);
                    }
                }

                if(ind != zpos.size()-1){
                    no0++;
                    if(no0*no0<=no1) ans++;
                }  
                prev = zpos[ind];
                ind++; 
                if(no0>=222) break;
            }
            cout<<ans<<" ";
        }

        return ans;
    }
};