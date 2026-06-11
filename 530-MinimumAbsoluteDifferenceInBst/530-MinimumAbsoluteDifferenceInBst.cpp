// Last updated: 6/11/2026, 11:32:42 AM
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
    int prev = 1e5;
    int mind = 1e9;

    int getMinimumDifference(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }

        getMinimumDifference(root->left);
        if(prev != 1e5){
            mind = min(mind, root->val - prev);
        }
        prev = root->val;
        getMinimumDifference(root->right);
        return mind;
    }
};