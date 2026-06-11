# Last updated: 6/11/2026, 11:35:45 AM
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        slow = head
        fast = head.next
        while(fast and fast.next):
            slow = slow.next
            fast = fast.next.next
        
        ll2 = slow.next
        slow.next = None

        prev = None
        curr = ll2
        while(curr):
            temp = curr.next
            curr.next = prev
            prev = curr
            curr = temp
        ll2 = prev
        ll1 = head
        while(ll2):
            n1,n2 = ll1.next, ll2.next
            ll1.next = ll2
            ll2.next = n1
            ll1 = n1
            ll2 = n2
        return head

        