// Last updated: 6/11/2026, 11:22:16 AM
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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root == nullptr){
            return nullptr;
        }

        deque<TreeNode*> q;
        q.push_back(root);

        int lvl = 0;
        while(!q.empty()){
            if(lvl%2 !=0){
                int l = 0;
                int r = q.size()-1;
                while(l<r){
                    swap(q[l]->val, q[r]->val);
                    l++;
                    r--;
                }
            }

            int sz = q.size();
            for(int i=0; i<sz; i++){
                TreeNode* cn = q.front();
                q.pop_front();
                if(cn->left){
                    q.push_back(cn->left);
                }
                if(cn->right){
                    q.push_back(cn->right);
                }
            }

            lvl++;
        }

        return root;
        

    }
};