// Last updated: 6/11/2026, 11:34:24 AM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==nullptr){
            return nullptr;
        }
        if(root==p || root==q){
            return root;
        } 

        TreeNode* sn1 = helper(root->left, p, q);
        TreeNode* sn2 = helper(root->right, p, q);

        if(sn1 != nullptr && sn2!=nullptr){
            return root;
        }
        if(sn1!=nullptr){
            return sn1;
        }
        if(sn2!=nullptr){
            return sn2;
        }
        return nullptr;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return helper(root, p, q);
    }
};