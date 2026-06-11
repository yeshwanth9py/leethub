// Last updated: 6/11/2026, 11:34:31 AM
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
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int> pq;
        
        stack<TreeNode*> st;

        st.push(root);
        while(!st.empty()){
            TreeNode* cn = st.top();
            st.pop();
            pq.push(cn->val);
            if(pq.size()>k){
                pq.pop();
            }
            if(cn->right){
                st.push(cn->right);
            }
            if(cn->left){
                st.push(cn->left);
            }
        }

        return pq.top();





    }
};