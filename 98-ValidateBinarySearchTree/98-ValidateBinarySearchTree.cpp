// Last updated: 6/11/2026, 11:36:48 AM
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
    bool helper(TreeNode* root, long long minv, long long maxv){
        if(root == nullptr){
            return true;
        }
        if(root->val>minv && root->val<maxv){
            return helper(root->left, minv, root->val) && helper(root->right, root->val, maxv);
        }
        return false;
    }

    bool isValidBST(TreeNode* root) {
        return helper(root, -1e18, 1e18);
    }

};