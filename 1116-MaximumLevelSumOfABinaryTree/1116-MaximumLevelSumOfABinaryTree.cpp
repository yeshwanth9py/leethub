// Last updated: 6/11/2026, 11:29:33 AM
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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int maxstn = -1e9;
        int maxlvl = 0;

        int lvl = 0;
        while(!q.empty()){
            int sz = q.size();
            lvl++;
            int curs = 0;
            for(int i=0; i<sz; i++){
                auto tn = q.front(); q.pop();
                if(tn->left){
                    q.push(tn->left);
                }
                if(tn->right){
                    q.push(tn->right);
                }
                curs += tn->val;
            }
            // cout<<curs<<" ";
            if(curs>maxstn){
                maxstn = curs;
                maxlvl = lvl;
            }
        }

        return maxlvl;


    }
};