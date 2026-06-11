// Last updated: 6/11/2026, 11:28:17 AM
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
    void inorder(TreeNode* root, vector<int> &arr){
        if(root == nullptr){
            return;
        }
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> arr1;
        inorder(root1, arr1);
        vector<int> arr2;
        inorder(root2, arr2);
        int l1 = arr1.size();
        int l2 = arr2.size();
        vector<int> ans(l1+l2, 0);
        int i = 0;
        int j = 0;
        int k = 0;
        while(i<l1 && j<l2){
            while(i<l1 && arr1[i]<=arr2[j]){
                ans[k] = arr1[i];
                k++;
                i++;
            }
            if(i>=l1){
                break;
            }
            while(j<l2 && arr1[i]>arr2[j]){
                ans[k] = arr2[j];
                k++;
                j++;
            }
        }
        while(i<l1){
            ans[k] = arr1[i];
            k++;
            i++;
        }
        while(j<l2){
            ans[k] = arr2[j];
            k++;
            j++;
        }
        return ans;

    }
};