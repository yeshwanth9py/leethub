// Last updated: 6/11/2026, 11:38:16 AM
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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !(head->next)){
            return head;
        }
        
        
        ListNode* dummy = new ListNode(head->val);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* cur = head;
        ListNode* next = head->next;

        while(cur && next){
            ListNode* temp = next->next;
            next->next = cur;
            cur->next = temp;
            prev->next = next;

            prev = cur;
            cur = temp;
            if(temp) next = temp->next;
        }

        return dummy->next;
    }
};