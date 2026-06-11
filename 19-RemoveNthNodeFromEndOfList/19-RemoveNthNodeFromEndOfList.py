# Last updated: 6/11/2026, 11:38:34 AM
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        if(head is None):
            return
        # curr = head
        # length = 0
        
        # while(curr):
        #     curr = curr.next
        #     length += 1

        # curr = head
        # cn = 0
        # gn = length - n + 1
        # if(length == n):
        #     return head.next
        # while(curr):
        #     cn += 1
        #     if(cn==gn-1):
        #         curr.next = curr.next.next
        #         return head
        #     curr = curr.next
        dummy = ListNode(0,head)
        first = dummy
        second = head
        
        while(n>0):
            second = second.next
            n -= 1

        while(second):
            first = first.next
            second = second.next

        first.next = first.next.next
        return dummy.next


        



        
            