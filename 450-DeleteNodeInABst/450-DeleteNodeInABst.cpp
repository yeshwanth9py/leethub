// Last updated: 6/11/2026, 11:33:04 AM
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
    int findrmin(TreeNode* root){
        int minv = root->val;

        while(root->left){
            root = root->left;
            minv = min(minv, root->val);
        }

        return minv;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr){
            return nullptr;
        }

        if(root->val == key){
            if(root->left == nullptr && root->right == nullptr){
                return nullptr;
            }

            else if(root->left == nullptr){
                return root->right;
            }

            else if(root->right == nullptr){
                return root->left;
            }

            else{
                root->val = findrmin(root->right);
                root->right = deleteNode(root->right, root->val);
                return root;
            }
        }

        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);

        return root;
    }
};