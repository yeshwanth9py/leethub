// Last updated: 6/11/2026, 11:29:39 AM
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
    vector<int> nextLargerNodes(ListNode* head) {
        stack<pair<int, int>> st;
        ListNode* temp = head;

        int len = 0;
        while(temp){
            len++;
            temp = temp->next;
        }
        temp = head;

        vector<int> ans(len, 0);

        int ind = 0;
        while(temp){
            while(!st.empty() && st.top().second<temp->val){
                auto elem = st.top();
                st.pop();
                ans[elem.first] = temp->val;
            }
            st.push({ind, temp->val});
            ind++;
            temp = temp->next;
        }

        while(!st.empty()){
            auto elem = st.top();
            st.pop();
            ans[elem.first] = 0;
        }

        return ans;

    }
};