// Last updated: 6/11/2026, 11:36:13 AM
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> um;
        queue<pair<string, int>> q;
        q.push({beginWord, 0});
        unordered_set<string> us(wordList.begin(), wordList.end());
        // us.insert(beginWord);
        us.erase(beginWord);
        vector<vector<string>> ans;
        um[beginWord] = 0;
        while(!q.empty()){
            auto cn = q.front();
            q.pop();
            string cw = cn.first;
            um[cw] = cn.second;
            for(int i=0; i<cw.size(); i++){
                char temp = cw[i];
                for(char ch='a'; ch<='z'; ch++){
                    if(ch==temp) continue;
                    cw[i] = ch;
                    if(us.find(cw)!=us.end()){
                        q.push({cw, cn.second+1});
                        us.erase(cw);
                    }
                    cw[i] = temp;
                }
            }
        }


        for(auto el: um){
            cout<<el.first<<"-"<<el.second<<"  ";
        }

        
        queue<vector<string>> q1;
        q1.push({endWord});
        while(!q1.empty()){
            vector<string> cv = q1.front();
            q1.pop();
            string cw = cv.back();
            if(cw == beginWord){
                reverse(cv.begin(), cv.end());
                ans.push_back(cv);
                continue;
            }
            for(int i=0; i<cw.size(); i++){
                char temp = cw[i];
                int plvl = um[cw];
                for(char ch = 'a'; ch<='z'; ch++){
                    if(ch == temp) continue;
                    cw[i] = ch;
                    if(um[cw] == plvl-1){
                        vector<string> newv = cv;
                        newv.push_back(cw);
                        q1.push(newv);
                    }
                    cw[i]=temp;
                }
            }
        }


        return ans;

        
    }
};