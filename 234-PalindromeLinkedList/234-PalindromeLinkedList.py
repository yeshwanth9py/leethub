# Last updated: 6/11/2026, 11:34:22 AM
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        dummyh = ListNode(0)

        cur = head
        curd = dummyh

        while(cur):
            curd.next = ListNode(cur.val)
            curd = curd.next
            cur = cur.next
        

        cur = head
        prev = None

        while(cur):
            temp = cur.next
            cur.next = prev
            prev = cur
            cur = temp

        ll1 = prev
        ll2 = dummyh.next
        while(ll1 and ll2):
            if(ll1.val != ll2.val):
                return False
            ll1 = ll1.next
            ll2 = ll2.next
        return True