// Last updated: 6/11/2026, 11:34:52 AM
struct Node{
    vector<Node*> arr;
    int ends = 0;
    Node(){
        arr.resize(26, nullptr);
        ends = 0;
    }
};


class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* cur = root;
        for(char ch: word){
            if(cur->arr[ch-'a']==nullptr){
                cur->arr[ch-'a'] = new Node();
            }
            cur = cur->arr[ch-'a'];
        }
        cur->ends++;
    }
    
    bool search(string word) {
        Node* cur = root;
        for(char ch: word){
            if(cur->arr[ch-'a'] == nullptr) return 0;
            cur = cur->arr[ch-'a'];
        }
        return cur->ends>0;
    }
    
    bool startsWith(string prefix) {
        Node* cur = root;
        for(char ch: prefix){
            if(cur->arr[ch-'a'] == nullptr) return 0;
            cur = cur->arr[ch-'a'];
        }
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */