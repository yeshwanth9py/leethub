// Last updated: 6/11/2026, 11:18:36 AM
struct node{
    node* child[26];
    int curl;
    int curind;
    node(){
        for(int i=0; i<26; i++){
            child[i] = nullptr;
        }
        curl = 0;
        curind = 1e9;
    }
    ~node(){
        for(int i=0; i<26; i++){
            delete child[i];
        }
    }   
};

struct trie{
    node* root;
    trie(){
        root = new node();
    }

    void add(string &s, int idx){
        node* cur = root;
        for(int i=s.size()-1; i>=0; i--){
            int ind = s[i]-'a';
            if(cur->child[ind] == nullptr){
                cur->child[ind] = new node();
                cur->child[ind]->curl = s.size();
                cur->child[ind]->curind = idx;
            }

            cur = cur->child[ind];

            if(cur->curl>s.size()){
                cur->curl = s.size();
                cur->curind = idx;
            }
        }
    }

    int findsmallsuf(string &s){
        node* cur = root;

        for(int i=s.size()-1; i>=0; i--){
            int ind = s[i]-'a';
            if(cur->child[ind] == nullptr) return cur->curind;
            cur = cur->child[ind];
        }

        return cur->curind;
    }

    ~trie(){
        delete root;
    }
};


class Solution {
public:
    vector<int> stringIndices(vector<string>& wcon, vector<string>& wq) {
        vector<int> ans;
        trie tr;

        int small = 1e9;
        int sml = -1;

        for(int i=0; i<wcon.size(); i++){
            tr.add(wcon[i], i);
            if(wcon[i].size() < small){
                small = wcon[i].size();
                sml = i;
            }
        }


        for(string w: wq){
            int cur = tr.findsmallsuf(w);
            if(cur == 1e9){
                ans.push_back(sml);
                continue;
            }
            ans.push_back(cur);
        }

        return ans;

    }
};