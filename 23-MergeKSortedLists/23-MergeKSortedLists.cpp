// Last updated: 6/11/2026, 11:38:19 AM
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* root = new ListNode(-1);
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>> > pq;
        for(auto el: lists){
            ListNode* cur = el;
            if(cur != nullptr){
                pq.push({cur->val, cur});
            }
        }

        ListNode* cur = root;
        while(!pq.empty()){
            auto tel = pq.top(); pq.pop();
            cur->next = tel.second;
            if(tel.second->next != nullptr){
                pq.push({tel.second->next->val, tel.second->next});
            }
            cur = cur->next;
            cur->next = nullptr;
        }

        return root->next;
    }
};