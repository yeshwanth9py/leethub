// Last updated: 6/11/2026, 11:13:25 AM
class Solution {
public:
    int longestBalanced(string s) {
        map<vector<int>, int> ump;
        map<pair<int, int>, int> ump1;
        map<pair<int, int>, int> ump2;
        map<pair<int, int>, int> ump3;

        int n = s.size();
        int a, b, c;
        a = b = c = 0;

        int maxl = 1;

        int cnt = 0;
        for(int i=0; i<n-1; i++){
            if(s[i] == s[i+1]){
                cnt++;
            }else{
                maxl = max(maxl, cnt+1);
                cnt = 0;
            }
        }
        maxl = max(maxl, cnt+1);


        for(int i=0; i<n; i++){
            if(s[i] == 'a'){
                a++;
            }else if(s[i] == 'b'){
                b++;
            }else{
                c++;
            }

            int c1 = a-b;
            int c2 = b-c;
            int c3 = c-a;
            if(c1 == 0 && c2 == 0 && c3 == 0){
                maxl = max(maxl, i+1);
            }
            if((c1 == 0 &&  c == 0) || (c2 == 0 && a == 0) || (c3 == 0 && b == 0)){
                maxl = max(maxl, i+1);
            }

            if(ump1.find({c1, c}) != ump1.end()){
                maxl = max(maxl, i-ump1[{c1, c}]);
            }else{
                ump1[{c1, c}] = i;
            }
            

            if(ump2.find({c2, a}) != ump2.end()){
                maxl = max(maxl, i-ump2[{c2, a}]);
            }else{
                ump2[{c2, a}] = i;
            }
            
            if(ump3.find({c3, b}) != ump3.end()){
                maxl = max(maxl, i-ump3[{c3, b}]);
            }else{
                ump3[{c3, b}] = i;
            }
            

            if(ump.find({c1, c2, c3}) != ump.end()){
                maxl = max(maxl, i-ump[{c1, c2, c3}]);
                if(maxl == 4){
                    cout<<ump[{c1, c2, c3}]<<endl;
                }
            }else{
                ump[{c1, c2, c3}] = i;
            }
        }

        return maxl;

    }
};