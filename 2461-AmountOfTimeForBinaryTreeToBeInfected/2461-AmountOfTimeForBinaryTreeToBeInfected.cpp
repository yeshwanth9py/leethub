// Last updated: 6/11/2026, 11:22:27 AM
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
    vector<vector<int>> adjl;
    vector<int> vis;
    void dfs(TreeNode* node){
        if(node == nullptr) return;
        int cur = node->val;
        if(node->left){
            adjl[cur].push_back(node->left->val);
            adjl[node->left->val].push_back(cur);
            dfs(node->left);
        }
        if(node->right){
            adjl[cur].push_back(node->right->val);
            adjl[node->right->val].push_back(cur);
            dfs(node->right);
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        adjl.resize(1e5+1, vector<int>());
        vis.resize(1e5+1, 0);


        dfs(root);
        
        queue<int> q;
        q.push(start);
        vis[start] = 1;
        int tim = -1;

        while(!q.empty()){
            int sz = q.size();
            tim++;
            for(int i=0; i<sz; i++){
                auto tel = q.front(); q.pop();
                for(int nei: adjl[tel]){
                    if(vis[nei] == 0){
                        q.push(nei);
                        vis[nei] = 1; 
                    }
                }
            }
        }
        
        return tim;
    }
};