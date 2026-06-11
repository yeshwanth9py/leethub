// Last updated: 6/11/2026, 11:33:26 AM
class Solution {
public:
    int lengthLongestPath(string input) {
        istringstream stream(input);
        string data;
        int totcnt = 0;
        int maxcnt = 0;
        stack<int> st;
        while(getline(stream, data)){
            int t=0;
            while(data[t] == '\t'){
                t++;
            }
            string subd = data.substr(t);
            while(!st.empty() && st.size()>t){
                totcnt -= st.top();
                st.pop();
            }
            if(subd.find(".")!=string::npos){
                maxcnt = max(maxcnt,  totcnt+(int) subd.length());
            }else{
                totcnt += subd.size() + 1;
                st.push(subd.size()+1);
            }
        }

        return maxcnt;
    }
};