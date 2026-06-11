// Last updated: 6/11/2026, 11:36:30 AM
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    int findlen(ListNode* head){
        if(head == nullptr){
            return 0;
        }
        ListNode* temp = head;
        int cnt = 0;
        while(temp){
            temp = temp->next;
            cnt++;
        }
        return cnt;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if(head == nullptr){
            return nullptr;
        }
        if(head->next == nullptr){
            return new TreeNode(head->val);
        }

        int len = findlen(head);
        int hf = len/2;
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while(hf--){
            prev = temp;
            temp = temp->next;
        }

        ListNode* next = temp->next;
        temp->next = nullptr;
        prev->next = nullptr;
        TreeNode* root = new TreeNode(temp->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(next);

        return root;

    }
};