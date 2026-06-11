// Last updated: 6/11/2026, 11:35:01 AM
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* cur = head;
        int cnt = 0;
        // Count the occurrences of the value in the list
        while (cur) {
            if (cur->val == val) {
                cnt++;
            }
            cur = cur->next;
        }
        // Remove the occurrences of the value
        for (int i = 0; i < cnt; i++) {
            cur = head;
            while (cur && cur->next) {
                if (cur->next->val == val) {
                    cur->next = cur->next->next;
                } else {
                    cur = cur->next;
                }
            }
        }

        // Check if the head itself needs to be removed
        if (head && head->val == val) {
            head = head->next;
        }

        return head;
    }
};