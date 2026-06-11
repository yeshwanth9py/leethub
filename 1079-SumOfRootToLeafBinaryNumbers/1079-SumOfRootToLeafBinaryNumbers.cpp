// Last updated: 6/11/2026, 11:29:38 AM
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
    int dfs(TreeNode* node, int s){
        if(node == nullptr){
            return 0;
        }
        if(node->left == nullptr && node->right == nullptr){
            s = s*2 + node->val;
            cout<<s<<" ";
            return s;
        }
        int v = node->val;
        s = s*2 + v;
        return dfs(node->left, s) + dfs(node->right, s);
    }
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }
};