// Last updated: 6/11/2026, 11:29:04 AM
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
    vector<int> all;
    int sz;
    void dfs(TreeNode* node){
        if(node == nullptr) return;
        all.push_back(node->val);
        dfs(node->left);
        dfs(node->right);
    }

    TreeNode* rec(int st, int en){
        if(st>en) return nullptr;
        if(st == en){
            return new TreeNode(all[st]);
        }

        int mid = (st+en)/2;
        TreeNode* cur = new TreeNode(all[mid]);
        cur->left = rec(st, mid-1);
        cur->right = rec(mid+1, en);
        return cur;
    }

    TreeNode* balanceBST(TreeNode* root) {
        dfs(root);
        sort(all.begin(), all.end());

        sz = all.size();
        return rec(0, sz-1);
    }
};

