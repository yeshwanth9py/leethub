// Last updated: 6/11/2026, 11:38:22 AM
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* newhead = new ListNode(0);

        ListNode* temp = newhead;

        ListNode* l1 = list1;
        ListNode* l2 = list2;

        while(l1 && l2){
            if(l1->val < l2->val){
                temp->next = l1;
                l1 = l1->next;
                temp = temp->next;
            }else{
                temp->next = l2;
                l2 = l2->next;
                temp = temp->next;
            }
        }

        if(l1){
            temp->next = l1;
            // l1 = l1->next;
        }

        if(l2){
            temp->next = l2;
            // l2=l2->next;
        }


        return newhead->next;
    }
};