// Last updated: 6/11/2026, 11:36:32 AM
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
    bool bal = 1;
    int dfs(TreeNode* node){
        if(node == nullptr) return 0;
        
        int lh = dfs(node->left);
        int rh = dfs(node->right);
        if(abs(lh-rh)>1){
            bal = 0;
        }
        return 1+max(lh, rh);
        
    }
    bool isBalanced(TreeNode* root) {
        bal = 1;
        dfs(root);
        return bal;
    }
};