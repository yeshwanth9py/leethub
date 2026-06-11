// Last updated: 6/11/2026, 11:22:15 AM
struct Node{
    Node* arr[26] = {nullptr};
    int cnt = 0;
    Node(){
        cnt = 0;
    }
};

struct Trie{
    Node* root;
    Trie(){
        root = new Node();
    }

    void insert(string &s){
        Node* cur = root;
        for(char ch: s){
            if(cur->arr[ch-'a'] == nullptr){
                cur->arr[ch-'a'] = new Node();
            }
            cur = cur->arr[ch-'a'];
            cur->cnt++;
        }
    }

    int getsumcnt(string &s){
        Node* cur = root;
        int cnt = 0;
        for(char ch: s){
            cur = cur->arr[ch-'a'];
            cnt += cur->cnt;
        }
        return cnt;
    }

    void deletenode(Node* node){
        if(!node) return;
        for(int i=0; i<26; i++){
            if(node->arr[i] != nullptr){
                deletenode(node->arr[i]);
            }
        }
        delete node;
    }

    ~Trie(){
        deletenode(root);
    }


};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int> ans;
        Trie tr;
        for(auto s: words){
            tr.insert(s);
        }

        for(auto s: words){
            ans.push_back(tr.getsumcnt(s));
        }

        return ans;

    }
};