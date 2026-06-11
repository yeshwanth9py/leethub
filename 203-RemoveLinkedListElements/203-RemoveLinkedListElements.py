# Last updated: 6/11/2026, 11:35:06 AM
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        cur = head
        cnt = 0
        while(cur):
            if(cur.val == val):
                cnt+=1
            cur = cur.next
        
        for i in range(cnt):
            cur = head
            while(cur and cur.next):
                if(cur.next.val == val):
                    cur.next = cur.next.next
                cur = cur.next
        
        if(head and head.val == val):
            return head.next

        return head