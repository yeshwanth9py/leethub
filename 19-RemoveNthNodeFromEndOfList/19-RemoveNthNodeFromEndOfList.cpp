// Last updated: 6/11/2026, 11:38:28 AM
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr || head->next == nullptr) return nullptr;
        ListNode* cur = head;
        ListNode* cur2 = head;

        int ct = 0;

        while(ct<n){
            cur2 = cur2->next;
            ct++;
        }

        while(cur2 && cur2->next){
            cur = cur->next;
            cur2 = cur2->next;
        }

        if(cur2 == nullptr){
            return head->next;
        }

        cur->next = cur->next->next;
        return head;

    }
};