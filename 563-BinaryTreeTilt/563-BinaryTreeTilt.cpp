// Last updated: 6/11/2026, 11:32:27 AM
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
    int helper(TreeNode* root){
        if(root ==nullptr){
            return 0;
        }
        int suml = helper(root->left);
        int sumr = helper(root->right);
        tsum += abs(suml-sumr);
        return root->val+suml+sumr;
    }
    
    int findTilt(TreeNode* root) {
        helper(root);
        return tsum;
    }
};