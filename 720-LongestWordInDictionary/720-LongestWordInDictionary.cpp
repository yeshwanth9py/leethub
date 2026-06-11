// Last updated: 6/11/2026, 11:31:42 AM

struct Node{
    vector<Node*> arr;
    int cnt = 0;
    Node(){
        arr.resize(26, nullptr);
        cnt = 0;
    }
};

struct Trie{
    Node* root;
    string small = "";
    Trie(){
        root = new Node();
    }

    void remove(string &s){
        Node* cur = root;
        Node* par = cur;

        for(char ch: s){
            if(cur->arr[ch-'a'] == nullptr) return;
            par = cur;
            cur = cur->arr[ch-'a'];

            if(cur->cnt == 1){
                par->arr[ch-'a'] = nullptr;
                delete cur;
                return;
            }else{
                cur->cnt--;
            }
        }

    }

    void insert(string &s){
        Node* cur = root;
        // cout<<
        int notp = 0;
        for(char ch: s){
            if(cur->arr[ch-'a'] == nullptr){
                notp++;
                cur->arr[ch-'a'] = new Node();
            }
            cur = cur->arr[ch-'a'];
            cur->cnt++;
        }

        if(notp>1) {
            remove(s);
            return;
        }
            
        if(small == ""){
            small = s;
        }else if(small.size()<s.size()){
            small = s;
        }else if(small.size()==s.size()){
            if(small>s){
                small = s;
            }
        }
    }

    string getans(){
        return small;
    }
};


class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        
        Trie tr;
        for(string w: words){
            tr.insert(w);
        }

        return tr.getans();
    }
};