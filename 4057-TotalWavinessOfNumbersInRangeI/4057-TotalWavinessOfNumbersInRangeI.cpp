// Last updated: 6/11/2026, 11:13:24 AM
class Solution {
public:
    int getwavyness(string &s){
        int n = s.size();
        int cnt = 0;
        for(int i=1; i<n-1; i++){
            if(s[i]-'0'>s[i-1]-'0' && s[i]-'0'>s[i+1]-'0'){
                cnt++;
            }else if(s[i]-'0'<s[i-1]-'0' && s[i]-'0'<s[i+1]-'0'){
                cnt++;
            }
        }
        return cnt;
    }
    
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        for(int i=num1; i<=num2; i++){
            string s = to_string(i);
            if(s.size()<=2) continue;
            int cur = getwavyness(s);
            ans += cur;
        }
        return ans;
    }
};