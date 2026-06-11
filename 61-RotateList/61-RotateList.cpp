// Last updated: 6/11/2026, 11:37:27 AM
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
    int findlen(ListNode* head){
        int len = 0;
        ListNode* cur = head;
        while(cur != nullptr){
            len++;
            cur = cur->next;
        }
        return len;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        int len = findlen(head);
        if(len == 0) return head;
        k = k%len;
        if(k == 0) return head;
        int bp = len-k;
        int cur = 1;
        ListNode* cur1 = head;
        while(cur<bp){
            cur1 = cur1->next;
            cur++;
        }

        ListNode* temp = cur1->next;
        cur1->next = nullptr;
        cur1 = temp;

        while(temp->next){
            temp = temp->next;
        }

        temp->next = head;

        return cur1;
    }
};




