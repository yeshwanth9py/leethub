// Last updated: 6/11/2026, 11:32:08 AM
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
    unordered_set<int> us;
    bool inorder(TreeNode* root, int k){
        if(root==nullptr){
            return false;
        }
        bool a = inorder(root->left, k);
        if(a){
            return true;
        }
        if(us.find(k-root->val)!=us.end()){
            return true;
        }
        us.insert(root->val);
        bool b = inorder(root->right, k);
        if(b){
            return true;
        }
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        us.clear();
        return inorder(root, k);
    }
};