// Last updated: 6/11/2026, 11:10:41 AM

struct node{
    node* b1 = nullptr;
    node* b0 = nullptr;
    int cnt = 0;
};

struct Trie{
    node* root;
    Trie(){
        root = new node();
    }
    void add(int numb){
        node* cur = root;
        for(int i=30; i>=0; i--){
            if(numb&(1LL<<i)){
                if(cur->b1 == nullptr){
                    cur->b1 = new node();
                }
                cur = cur->b1;
                (cur->cnt)++;
            }else{
                if(cur->b0 == nullptr){
                    cur->b0 = new node();
                }
                cur = cur->b0;
                (cur->cnt)++;
            }
        }
    }

    void remove(int numb){
        node* cur = root;
        for(int i=30; i>=0; i--){
            if((numb&(1LL<<i))){
                cur = cur->b1;
                cur->cnt--;
                // if(cur->cnt == 0){
                //     // delete cur;
                //     return;
                // }
            }else{
                cur = cur->b0;
                cur->cnt--;
                // if(cur->cnt == 0){
                //     // delete cur;
                //     return;
                // }
            }
        }
    }

    int getmax(int numb){
        int ans = 0;
        node* cur = root;
        for(int i=30; i>=0; i--){
            if((numb&(1LL<<i))){
                if(cur->b0 != nullptr && cur->b0->cnt>0){
                    cur = cur->b0;
                    ans |= (1LL<<i);
                }else{
                    cur = cur->b1;
                }
            }else{
                if(cur->b1 != nullptr && cur->b1->cnt>0){
                    cur = cur->b1;
                    ans |= (1LL<<i);
                }else{
                    cur = cur->b0;
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    int maxXor(vector<int>& nums, int k) {
        Trie tr;
        int i=0;
        int j=-1;
        int n = nums.size();

        vector<int> pref(n, 0);
        pref[0] = nums[0];
        for(int i=1; i<n; i++){
            pref[i] = (pref[i-1] ^ nums[i]);
        }
        
        int maxor = *max_element(nums.begin(), nums.end());
        multiset<int> ms1;

        tr.add(0);
        
        while(i<n){
            while(j+1<n && (j+1 == i || max(*ms1.rbegin(), nums[j+1])-min(*ms1.begin(), nums[j+1]) <= k)){
                j++;
                ms1.insert(nums[j]);
                
                maxor = max(maxor, tr.getmax(pref[j]));
                
                tr.add(pref[j]);
            }
            cout<<i<<" "<<j<<endl;

            if(i>j){
                i++;
                j=i-1;
            }else{ 
                ms1.erase(ms1.find(nums[i]));
                if(i == 0){
                    tr.remove(0);
                }else{
                    tr.remove(pref[i-1]);
                }
                i++;
            }
        }
        return maxor;
    }
};


