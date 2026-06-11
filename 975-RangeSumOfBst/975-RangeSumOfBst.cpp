// Last updated: 6/11/2026, 11:30:16 AM
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
    int tsum = 0;
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == nullptr){
            return 0;
        }
        if(root->val >= low && root->val <= high){
            tsum += root->val;
        }
        rangeSumBST(root->left, low, high);
        rangeSumBST(root->right, low, high);
        return tsum;
        

    }
};