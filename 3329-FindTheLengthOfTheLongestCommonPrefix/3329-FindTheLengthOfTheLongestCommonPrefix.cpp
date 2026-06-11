// Last updated: 6/11/2026, 11:18:50 AM

struct node{
    vector<node*> child;
    int cnt;
    node(){
        child.resize(10, nullptr);
        cnt = 0;
    }
};

struct Trie{
    node* root;
    Trie(){
        root = new node();
    }

    void addn(int num){
        string s = to_string(num);
        node* cur = root;
        for(int i=0; i<s.size(); i++){
            int fd = s[i]-'0';
            if(cur->child[fd] == nullptr){
                cur->child[fd] = new node();
            }
            cur = cur->child[fd];
            (cur->cnt)++;
        }
    }

    int findmxpre(int num){
        string s = to_string(num);
        node* cur = root;
        int curl = 0;
        for(int i=0; i<s.size(); i++){
            int fd = s[i]-'0';
            if(cur->child[fd] == nullptr){
                return curl;
            }
            cur = cur->child[fd];
            curl++;
        }

        return curl;
    }

};


class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie tr;
        for(int el: arr1){
            tr.addn(el);
        }
        int ans = 0;
        for(int el: arr2){
            int kx = tr.findmxpre(el);
            ans = max(ans, kx);
        }

        return ans;
    }
};

