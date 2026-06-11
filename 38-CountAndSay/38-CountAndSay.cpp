// Last updated: 6/11/2026, 11:38:04 AM
class Solution {
public:
    unordered_map<int, string> ump;
    string countAndSay(int n) {
        if(ump.find(n)!=ump.end()){
            return ump[n];
        }
        if(n==1){
            return ump[n] = "1";
        }else if(n==2){
            return ump[n] = "11";
        }else{
            string temp = countAndSay(n-1);
            string ans = "";
            int nn = temp.size();
            int i=0;
            while(i<nn){
                int cnt = 0;
                int j = i;
                while(j<nn && temp[i] == temp[j]){
                    cnt++;
                    j++;
                }
                ans += to_string(cnt)+temp[i];
                i = j;
            }
            return ump[n] = ans;
        }
    }
};