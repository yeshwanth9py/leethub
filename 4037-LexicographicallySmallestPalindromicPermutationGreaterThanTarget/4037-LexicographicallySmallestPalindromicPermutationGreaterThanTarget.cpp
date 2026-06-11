// Last updated: 6/11/2026, 11:13:39 AM
class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        multiset<char> ms;
        unordered_map<char, int> ump;
        for(char ch: s){
            ump[ch]++;
        }
        string m = "";
        int n = s.size();
        for(auto el: ump){
            if((el.second%2) == 1 && (n%2 == 0)) return "";
            if((el.second%2) == 1){
                if(m!=""){
                    return "";
                }
                m.push_back(el.first);
                // cout<<m<<" "<<el.first<<endl;
                int cnt = (el.second-1)/2;
                while(cnt--){
                    ms.insert(el.first);
                }
            }else{
                int cnt = el.second/2;
                while(cnt--){
                    ms.insert(el.first);
                }
            }
        }

        string cur = "";
        string ans = string(n, '{');

        for(int i=0; i<n/2; i++){
            // cout<<i<<" ";
            auto it = ms.upper_bound(target[i]);
            if(it!=ms.end()){
                string temp = cur;
                char thatchar = *it;
                temp.push_back(thatchar);
                ms.erase(ms.find(thatchar));
                for(auto ch: ms){
                    temp.push_back(ch);
                }
                string temp2 = temp;
                reverse(temp2.begin(), temp2.end());
                string curfull = temp + m + temp2;
                // cout<<"curf "<<curfull<<" ";
                if(curfull<ans){
                    ans = curfull;
                }
                ms.insert(thatchar);
            }
            
            if(ms.find(target[i])!=ms.end()){
                // cout<<"okjh";
                cur.push_back(target[i]);
                ms.erase(ms.find(target[i]));
            }else{
                break;
            }
        }

        // cout<<"out"<<endl;
        // cout<<cur<<" ";

        string temp2 = cur;
        reverse(temp2.begin(), temp2.end());
        string temp = cur+m+temp2;
        cout<<temp<<endl;
        if(temp>target && temp.size() == target.size()) return temp;
        
        if(ans == string(n, '{')) return "";
        return ans;


    }
};