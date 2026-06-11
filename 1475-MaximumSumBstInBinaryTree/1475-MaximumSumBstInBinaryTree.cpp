// Last updated: 6/11/2026, 11:27:57 AM
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
class Node{
    public:
        int maxval;
        int minval;
        int tsum;
        Node(int mav, int miv, int ts){
            maxval = mav;
            minval = miv;
            tsum = ts;
        }
};


class Solution {
public:
    int maxsum = 0;
    Node helper(TreeNode* root){
        if(root == nullptr){
            return Node(-1e9, 1e9, 0);
        }

        Node ln = helper(root->left);
        Node rn = helper(root->right);

        if(root->val>ln.maxval && root->val<rn.minval){
            int maxv = max(root->val, rn.maxval);
            int minv = min(root->val, ln.minval);
            maxsum = max(maxsum, root->val+ln.tsum+rn.tsum);
            return Node(maxv, minv, root->val+ln.tsum+rn.tsum);
        }

        return Node(1e9, -1e9, max(ln.tsum, rn.tsum));
    }


    int maxSumBST(TreeNode* root) {
        maxsum = 0;
        Node rn = helper(root);
        return maxsum;
    }
};