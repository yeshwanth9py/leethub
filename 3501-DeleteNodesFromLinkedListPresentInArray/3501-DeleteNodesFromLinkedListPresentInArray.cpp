// Last updated: 6/11/2026, 11:17:51 AM
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* newh = new ListNode();
        newh->next = head;
        unordered_map<int, int> ump;
        for(int el: nums){
            ump[el] = 1;
        }

        ListNode* cur = newh;

        // cout<<cur->val<<endl;

        while(cur!=nullptr){
            if(cur->next == nullptr) break;
            int nextval = cur->next->val;
            if(ump.find(nextval)!=ump.end()){
                ListNode* temp = cur->next->next;
                cur->next = temp;
            }else{
                cur = cur->next;
            }
        }

        return newh->next;
    }
};