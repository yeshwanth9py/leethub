// Last updated: 6/11/2026, 11:38:51 AM
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
    ListNode* reverse(ListNode* node){
        ListNode* cur = node;
        ListNode* next;
        ListNode* prev = nullptr;

        while(cur){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = l1;
        l2 = l2;

        ListNode* t1 = l1;
        ListNode* t2 = l2;

        ListNode* newh = new ListNode(0);
        ListNode* t= newh;

        int carry = 0;
        while(t1 && t2){
            int actsum = t1->val + t2->val + carry;
            t->next = new ListNode(actsum%10);
            carry = actsum/10;
            t1 = t1->next;
            t2 = t2->next;
            t = t->next;
        }

        while(t1){
            int actsum = t1->val+carry;
            t->next = new ListNode(actsum%10);
            t1 = t1->next;
            t = t->next;
            carry = actsum/10;
        }

        while(t2){
            int actsum = t2->val + carry;
            t->next = new ListNode(actsum%10);
            t2 = t2->next;
            t = t->next;
            carry = actsum/10;
        }

        if(carry){
            t->next = new ListNode(carry);
            t = t->next;
        }

        return newh->next;


    }
};