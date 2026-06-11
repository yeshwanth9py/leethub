// Last updated: 6/11/2026, 11:32:36 AM
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
    int maxd = 0;
    int helper(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int lh = 0;
        if(root->left){
            lh = 1+helper(root->left);
        }
        
        int rh = 0;
        if(root->right){
            rh = 1+helper(root->right);
        }

        maxd = max({maxd, lh, rh, lh+rh});

        // if(root->left == nullptr && root->right == nullptr){
        //     return 1;
        // }

        return max(lh, rh);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        helper(root);
        return maxd;
    }

    
};