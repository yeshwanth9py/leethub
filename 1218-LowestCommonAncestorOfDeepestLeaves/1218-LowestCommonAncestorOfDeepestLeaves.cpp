// Last updated: 6/11/2026, 11:29:18 AM
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
    TreeNode* ans = nullptr;
    unordered_map<TreeNode*, int> ump;
    int helperht(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int lh = helperht(root->left);
        int rh = helperht(root->right);

        ump[root] = 1+max(lh, rh);
        return ump[root];
    }

    void helper2(TreeNode* node){
        if(node == nullptr){
            return;
        }
        int lh = 1;
        int rh = 1;

        if(node->left != nullptr){
            lh += ump[node->left];
        }
        if(ans != nullptr){
            return;
        }
        if(node->right != nullptr){
            rh += ump[node->right];
        }

        if(lh == rh){
            ans = node;
            return;
        }
        else if(lh>rh){
            helper2(node->left);
        }else{
            helper2(node->right);
        }

    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        ans = nullptr;
        helperht(root);
        helper2(root);
        return ans;
    }
};