// Last updated: 6/11/2026, 11:25:16 AM
class Solution {
public:
    unordered_map<int, int> allsqs;
    void pre(){
        for(int i=1; i<=250; i++){
            allsqs[i*i] = i;
        }        
    }
    int countTriples(int n) {
        int cnt = 0;
        pre();
        for(int i=1; i<n; i++){
            for(int j=1; j<n; j++){
                int c = i*i+j*j;
                if(allsqs.find(c) != allsqs.end() && allsqs[c]<=n){
                    cnt+=1;
                }
            }
        }
        return cnt;
    }
};