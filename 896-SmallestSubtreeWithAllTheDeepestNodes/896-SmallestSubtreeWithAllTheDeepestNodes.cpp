// Last updated: 6/11/2026, 11:30:43 AM
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
    map<int, vector<TreeNode*>> dist;
    map<TreeNode*, TreeNode*> par;
    int maxd;
    int timer;
    map<TreeNode*, int> intime;
    map<TreeNode*, int> outtime;

    bool isinside(TreeNode *cur1, TreeNode* cur2){
        if(intime[cur1]<=intime[cur2] && outtime[cur1]>=outtime[cur2]){
            return 1;
        }
        return 0;
    }

    void dfs(TreeNode* node, TreeNode* pp, int dd){
        if(node == nullptr) return;
        dist[dd].push_back(node);
        par[node] = pp;

        timer++;
        intime[node] = timer;
        maxd = max(maxd, dd);

        dfs(node->left, node, dd+1);
        dfs(node->right, node, dd+1);

        timer++;
        outtime[node] = timer;
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        maxd = 0;
        timer = 0;
        dfs(root, nullptr, 0);
        
        auto bn = dist[maxd].back();
        dist[maxd].pop_back();
        if(dist[maxd].size() == 0) return bn;
        int j = dist[maxd].size()-1;
        while(j>=0){
            if(isinside(bn, dist[maxd][j])){
                j--;
            }else{
                bn = par[bn];
            }
        }

        return bn;

        


    }
};