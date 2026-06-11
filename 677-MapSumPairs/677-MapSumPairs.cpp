// Last updated: 6/11/2026, 11:32:00 AM
struct Node{
    vector<Node*> arr; 
    unordered_map<string, int> ump;
    int val = 0;
    int isend = 0;
    Node(){
        arr.resize(26, nullptr);
        val = 0;
        isend = 1;
    }
};


struct Trie{
    Node* root;
    Trie(){
        root = new Node();
    }

    void insert(string &s, int val){
        Node* cur = root;
        for(char ch: s){
            if(cur->arr[ch-'a'] == nullptr){
                cur->arr[ch-'a'] = new Node();
            }
            cur = cur->arr[ch-'a'];
            cur->val += val;
            if(cur->ump.find(s)!= cur->ump.end()){
                int prev = cur->ump[s];
                cur->val -= prev;
                cur->ump[s] = val;
            }else{
                cur->ump[s] = val;
            }
        }
    }

    int getsum(string &pref){
        Node* cur = root;
        for(char ch: pref){
            if(cur->arr[ch-'a'] == nullptr){
                cur->arr[ch-'a'] = new Node();
            }
            cur = cur->arr[ch-'a'];
        }
        return cur->val;
    }
};

class MapSum {
public:
    Trie* tr = nullptr;
    MapSum() {
        tr = new Trie();
    }
    
    void insert(string key, int val) {
        tr->insert(key, val);
    }
    
    int sum(string prefix) {
        return tr->getsum(prefix);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */