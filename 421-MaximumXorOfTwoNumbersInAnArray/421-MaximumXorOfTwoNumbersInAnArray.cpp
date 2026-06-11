// Last updated: 6/11/2026, 11:33:09 AM
struct Node{
    Node* arr[2];
    Node(){
        arr[0] = nullptr;
        arr[1] = nullptr;
    }
};

struct Trie{
    Node* root;
    Trie(){
        root = new Node();
    }

    void insert(int num){
        Node* cur = root;
        for(int i=31; i>=0; i--){
            if(num&(1LL<<i)){
                if(cur->arr[1] == nullptr){
                    cur->arr[1] = new Node();
                }
                cur = cur->arr[1];
            }else{
                if(cur->arr[0] == nullptr){
                    cur->arr[0] = new Node();
                }
                cur = cur->arr[0];
            }
        }
    }


    int findmaxor(int num){
        int ans = 0;
        Node* cur = root;
        for(int i=31; i>=0; i--){
            if(num&(1LL<<i)){
                if(cur->arr[0] != nullptr){
                    cur = cur->arr[0];
                    ans |= (1LL<<i);
                }else{
                    cur = cur->arr[1];
                }
            }else{
                if(cur->arr[1] != nullptr){
                    cur = cur->arr[1];
                    ans |= (1LL<<i);
                }else{
                    cur = cur->arr[0];
                }
            }
        }
        return ans;
    }

};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie tr;
        for(int el: nums){
            tr.insert(el);
        }

        int maxans = 0;
        for(int el: nums){
            int cur = tr.findmaxor(el);
            maxans = max(maxans, cur);
        }
        return maxans;
    }
};