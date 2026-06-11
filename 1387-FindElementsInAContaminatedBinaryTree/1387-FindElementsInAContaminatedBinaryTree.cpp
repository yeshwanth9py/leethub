// Last updated: 6/11/2026, 11:28:37 AM
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
class FindElements {
public:
    TreeNode* root = nullptr;
    void traverse(TreeNode* node){
        if(node == nullptr){
            return;
        }
        int x = node->val;
        if(node->left){
            node->left->val = 2*x+1;
        }

        if(node->right){
            node->right->val = 2*x+2;
        }

        traverse(node->left);
        traverse(node->right);
    }

    FindElements(TreeNode* root) {
        root->val = 0;
        this->root = root;
        traverse(root);
    }

    bool findnode(TreeNode* node, int target){
        if(node==nullptr){
            return false;
        }
        if(node->val == target){
            return true;
        }
        return findnode(node->left, target) || findnode(node->right, target);
    }
    
    bool find(int target) {
        return findnode(root, target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */