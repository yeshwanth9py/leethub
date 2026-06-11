// Last updated: 6/11/2026, 11:17:54 AM
class Solution {
public:
    int maxOperations(string s) {
        int n = s.size();
        vector<int> onep;
        for(int i=0; i<n; i++){
            if(s[i] == '1'){
                onep.push_back(i);
            }
        }

        onep.push_back(n);

        int op = 0;
        for(int i=0; i<onep.size()-1; i++){

            if(onep[i+1]-onep[i]-1>0){
                op += (i+1);
            }
            // cout<<i<<" "<<(onep[i+1]-onep[i]-1)<<endl;
        }

        return op;

    }
};