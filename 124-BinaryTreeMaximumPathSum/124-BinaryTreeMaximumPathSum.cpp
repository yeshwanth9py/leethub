// Last updated: 6/11/2026, 11:36:18 AM
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
    int maxans = 0;
    int rec(TreeNode* root){
        if(root == nullptr){
            return -1e9;
        }

        int cur = root->val;
        int lefts = rec(root->left);
        int rights = rec(root->right);

        int pans =  max({lefts+cur, cur, rights+cur, cur}); 
        maxans = max({maxans, pans, lefts + rights + cur});

        return pans;
    }

    int maxPathSum(TreeNode* root) {
        maxans = -1e9;
        rec(root);
        return maxans;
    }
};