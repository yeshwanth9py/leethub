// Last updated: 6/11/2026, 11:28:24 AM
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
    int getlen(ListNode* cur){
        if(cur == nullptr) return 0;
        ListNode* fast = cur;
        ListNode* slow = cur;
        int cnt = 0;

        while(fast && fast->next){
            slow = slow->next;
            cnt++;
            fast = fast->next->next;
        }

        if(fast == nullptr){
            cnt = cnt*2;
        }else if(fast->next == nullptr){
            cnt = cnt*2+1;
        }

        return cnt;
    }
    int getDecimalValue(ListNode* head) {
        int len = getlen(head);
        ListNode* cur = head;
        int ci = len-1;
        int ans = 0;
        cout<<len;
        while(cur && ci>=0){
            if(cur->val){
                ans += (1LL<<(ci));
            }
            cur = cur->next;
            ci--;
        }

        return ans;
    }
};