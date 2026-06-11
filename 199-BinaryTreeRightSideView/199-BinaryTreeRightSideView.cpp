// Last updated: 6/11/2026, 11:35:07 AM
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
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr){
            return {};
        }
        queue<TreeNode*> q;
        q.push(root);
        vector<int> ans;
        while(!q.empty()){
            int sz = q.size();
            // bool flag = false;
            for(int i=0; i<sz; i++){
                TreeNode* curn = q.front();
                if(i==0){
                    ans.push_back(curn->val);
                }
                q.pop();
                if(curn->right){
                    q.push(curn->right);
                }
                if(curn->left){
                    q.push(curn->left);
                }
            }
        }

        return ans;
    }
};