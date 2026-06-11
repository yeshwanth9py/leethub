// Last updated: 6/11/2026, 11:37:01 AM
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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* prev = head;
        ListNode* cur = head->next;
        while(cur){
            if(cur->val == prev->val){
                cur = cur->next;
            }else{
                prev->next = cur;
                cur = cur->next;
                prev = prev->next;
            }
        }
        prev->next = nullptr;

        return head;
    }
};