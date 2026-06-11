// Last updated: 6/11/2026, 11:29:37 AM
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

    TreeNode* recoverFromPreorder(string traversal) {
        int n = traversal.length();
        stack<TreeNode*> st;
        TreeNode* rootnode = new TreeNode(0);
        st.push(rootnode);
        int plvl = -1;
        int i=0;
        int curlvl = 0;
        while(i<n){
            while(i<n && traversal[i]=='-'){
                curlvl++;
                i++;
            }
            string curnum = "";
            while(i<n && traversal[i]!='-'){
                curnum+=traversal[i];
                i++;
            }
        

            if(curlvl==plvl+1){
                TreeNode* curnode = new TreeNode(stoi(curnum));
                TreeNode* pnode = st.top();
                pnode->left = curnode;
                st.push(curnode);
            }else if(curlvl == plvl){
                st.pop();
                TreeNode* pnode = st.top();
                TreeNode* curnode = new TreeNode(stoi(curnum));
                pnode->right = curnode;
                st.push(curnode);
            }else{
                int nop = -curlvl + plvl+1;
                while(nop--) st.pop();
                TreeNode* pnode = st.top();
                TreeNode* curnode = new TreeNode(stoi(curnum));
                pnode->right = curnode;
                st.push(curnode);
            }
            plvl = curlvl;
            curlvl = 0;
        }

        while(st.size()>1){
            st.pop();
        }
        if(st.empty()) return nullptr;
        return st.top()->left;


    }
};