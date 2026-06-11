// Last updated: 6/11/2026, 11:29:22 AM
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
    unordered_map<TreeNode*, int> ump;

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete){
        delNodes2(root, to_delete);
        vector<TreeNode*> ans;

        for(auto el: ump){
            if(el.second == 1 && el.first!=nullptr){
                ans.push_back(el.first);
            }
        }

        bool flag = false;
        for(int el: to_delete){
            if(el == root->val){
                flag = true;
            }
        }

        if(flag == false && ump.find(root)==ump.end()){
            ans.push_back(root);
        }

        return ans;
    }

    TreeNode* delNodes2(TreeNode* root, vector<int>& to_delete) {

        if(root == nullptr){
            return nullptr;
        }
       
        for(int el: to_delete){
            if(el == root->val){
                if(ump.find(root)!=ump.end()){
                    ump[root] = 0;
                }
                ump[root->left] = 1;
                ump[root->right] = 1;

                delNodes2(root->left, to_delete);
                delNodes2(root->right, to_delete);
                return nullptr;
            }
        }

        root->left = delNodes2(root->left, to_delete);
        root->right = delNodes2(root->right, to_delete);

        return root;
    }
};