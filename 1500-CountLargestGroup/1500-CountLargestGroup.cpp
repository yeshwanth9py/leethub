// Last updated: 6/11/2026, 11:27:48 AM
class Solution {
public:

    int sum1(int num){
        int s = 0;
        while(num){
            int ld = num%10;
            s = (s+ld);
            num /= 10;
        }
        return s;
    }

    int countLargestGroup(int n) {
        unordered_map<int, int> ump;
        int lsz = 0;
        for(int i=1; i<=n; i++){
            int cursum = sum1(i);
            ump[cursum]++;
            lsz = max(lsz, ump[cursum]);
        }
        
        int gsno = 0;
        for(auto el: ump){
            // cout<<el.first<<" "<<el.second<<endl;
            if(el.second == lsz){
                gsno++;
            }
        }
        return gsno;
    }
};