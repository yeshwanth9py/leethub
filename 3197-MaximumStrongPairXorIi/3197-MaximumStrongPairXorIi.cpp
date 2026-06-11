// Last updated: 6/11/2026, 11:19:30 AM
struct Node{
    Node* arr[2];
    int cnt = 0;
    Node(){
        arr[0] = arr[1] = nullptr;
        cnt = 0;
    }
};

struct Trie{
    Node* root;
    Trie(){
        root = new Node();
    }

    void insert(int numb){
        Node* cur = root;
        for(int i=31; i>=0; i--){
            int sch = 0;
            if(numb&(1LL<<i)){
                sch = 1;
            }
            if(cur->arr[sch] == nullptr){
                cur->arr[sch] = new Node();
            }
            cur = cur->arr[sch];
            cur->cnt++;
        }
    }

    int getmaxor(int numb){
        Node* cur = root;
        int ans = 0;
        for(int i=31; i>=0; i--){
            int sch = 0;
            if(numb&(1LL<<i)){
                sch = 1;
            }
            if(cur->arr[1-sch] != nullptr && cur->arr[1-sch]->cnt>0){
                ans |= (1LL<<i);
                cur = cur->arr[1-sch];
            }else{
                if(cur->arr[sch] == nullptr || cur->arr[sch]->cnt<=0) return ans;
                cur = cur->arr[sch];
            }
        }
        return ans;
    }

    void remove(int numb){
        Node* cur = root;
        for(int i=31; i>=0; i--){
            int sch = 0;
            if(numb&(1LL<<i)){
                sch = 1;
            }
            if(cur->arr[sch] == nullptr) return;
            cur = cur->arr[sch];
            cur->cnt--;
        }
    }
};


class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        Trie tr;
        int n = nums.size();

        int b = n-1;
        int ans = 0;
        for(int i=n-1; i>=0; i--){
            // cout<<nums[i]<<": ";
            while(b>=0 && nums[b]>=(nums[i]+1)/2){
                tr.insert(nums[b]);
                b--;
            }
            int cur = tr.getmaxor(nums[i]);
            // cout<<cur<<endl;
            ans = max(ans, cur);
            tr.remove(nums[i]);
        }

        return ans;
    }
};