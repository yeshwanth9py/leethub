// Last updated: 6/11/2026, 11:16:46 AM
class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends == 1){
            return word;
        }

        int len = word.size();
        int stl = len-numFriends+1;

        string maxst = "";
        for(int i=0; i<len; i++){
            string cur = word.substr(i, stl);
            if(cur>maxst){
                maxst = cur;
            }
        }

        return maxst;
    }
};