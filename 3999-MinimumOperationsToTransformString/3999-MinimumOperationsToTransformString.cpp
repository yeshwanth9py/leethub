// Last updated: 6/11/2026, 11:14:05 AM
class Solution {
public:
    int minOperations(string s) {
        vector<int> arr(26, 0);

        vector<int> temp;
        for(int i=0; i<s.length(); i++){
            if(s[i] == 'a') continue;
            arr[s[i]-'a'] = 1;
        }

        for(int i=1; i<=25; i++){
            if(arr[i] == 0) continue; 
            temp.push_back(i);
        }
        
        sort(temp.begin(), temp.end());

        int op = 0;
        for(int i=0; i<temp.size(); i++){
            cout<<temp[i]<<" ";
            if(i+1<temp.size()){
                op += (temp[i+1]-temp[i]);
            }else{
                op += (25-temp[i])+1;
            }
        }
        
        
        return op;
    }
};