// Last updated: 6/11/2026, 11:10:25 AM
class Solution {
public:
    int minOperations(string s) {
        int ans = 4;
        int n = s.size();
        if(n == 1) return 0;
        if(n==2 && s[n-1]<s[0]) return -1;
        
        int pc = -1;
        bool np = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i]-'a' >= pc){
                pc = s[i]-'a';
            }else{
                np = 1;
                break;
            }
        }
        if(np == 0) return 0;

        string dup1 = s;
        string dup2 = s;
        sort(dup1.begin(), dup1.begin()+n-1);
        sort(dup2.begin()+1, dup2.end());
        cout<<dup1<<endl;
        cout<<dup2<<endl;

        //1
        if(dup1[n-1]<dup1[0]){
            ans = min(ans, 3);
        }else if(dup1[n-1]>=dup1[n-2]){
            ans = min(ans, 1);
        }else{
            ans = min(ans, 2);
        }

        //2
        if(dup2[0]>dup2[n-1]){
            //np
            ans = min(ans, 3);
        }else if(dup2[0]<=dup2[1]){
            ans = min(ans, 1);
        }else{
            ans = min(ans, 2);
        }
        
        if(ans == 4) return -1;
        
        return ans;




        
    }
};