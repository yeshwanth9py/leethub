// Last updated: 6/11/2026, 11:28:00 AM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     long long val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(long long x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(long long x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long maxs = 0;
    long long tots = 0;
    const long long mod = 1e9+7;
    unordered_map<TreeNode*, long long> subsm;
    long long dfssm(TreeNode* node){
        if(node == nullptr){
            return 0;
        }
        long long curs = node->val;
        curs += dfssm(node->left);
        // curs = (curs%mod + mod)%mod;
        curs += dfssm(node->right);
        // curs = (curs%mod + mod)%mod;
        subsm[node] = curs;
        return curs;
    }

    void dfs(TreeNode* node){
        if(node == nullptr) return;
        if(node->left){
            long long curpr = (((subsm[node->left] * ((tots-subsm[node->left])))));
            maxs = max(maxs, curpr);
            dfs(node->left);
        }
        if(node->right){
            long long curpr = (subsm[node->right] * ((tots-subsm[node->right])));
            maxs = max(maxs, curpr);
            dfs(node->right);
        }
    }

    int maxProduct(TreeNode* root) {
        dfssm(root);
        tots = subsm[root];
        dfs(root);
        return maxs%mod;
    }
};