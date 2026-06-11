// Last updated: 6/11/2026, 11:23:21 AM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<int, TreeNode*> mp; 
    TreeNode* createBinaryTree(vector<vector<int>>& arr) {
        mp.clear();
        unordered_map<int, int> par;
        for(auto el: arr){
            int p = el[0];
            int c = el[1];
            int dir = el[2];
            par[c] = p;

            if(mp.find(p)==mp.end()){
                mp[p] = new TreeNode(p);
            }

            if(mp.find(c)==mp.end()){
                mp[c] = new TreeNode(c);
            }

            if(dir){
                mp[p]->left = mp[c];
            }else{
                mp[p]->right = mp[c];
            }
        }

        int cur = arr[0][0];

        while(par.find(cur) != par.end()){
            cur = par[cur];
        }

        return mp[cur];
    }
};






