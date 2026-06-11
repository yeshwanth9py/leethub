// Last updated: 6/11/2026, 11:35:39 AM
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
    ListNode* merge2slists(ListNode* left, ListNode* right, ListNode* rend){
        ListNode* nhead = new ListNode(0);
        ListNode* lend = right;
        ListNode* nit = nhead;
        while(left && right && left!=lend && right!=rend){
            if(left->val<=right->val){
                nit->next = new ListNode(left->val);
                nit=nit->next;
                left = left->next;
            }else{
                nit->next = new ListNode(right->val);
                nit = nit->next;
                right = right->next;
            }
        }
        while(left && left!=lend){
            nit->next = new ListNode(left->val);
            nit=nit->next;
            left = left->next;
        }
        while(right && right!=rend){
            nit->next = new ListNode(right->val);
            nit = nit->next;
            right = right->next;
        }

        return nhead->next;
    }

    ListNode* findmiddle(ListNode* head, ListNode* end){
        if(head==end || head->next == end){
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast!=end && fast->next!=end){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* mergesort(ListNode* head, ListNode* end){
        if(head == end){
            return head;
        }
        if(head == nullptr){
            return nullptr;
        }
        ListNode* mid = findmiddle(head, end->next);
        ListNode* left = mergesort(head, mid);
        ListNode* right = mergesort(mid->next, end);
        return merge2slists(left, right, end->next);
    }

    ListNode* sortList(ListNode* head) {
        ListNode* end = head;
        while(end && end->next){
            end = end->next;
        }
        return mergesort(head, end);
    }
};