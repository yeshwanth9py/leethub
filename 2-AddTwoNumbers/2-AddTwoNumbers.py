# Last updated: 6/11/2026, 11:38:56 AM
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        sum1 = 0
        carry = 0
        l3 = ListNode()
        head = l3
        while(l1!=None or l2!=None or carry!=0):
            if(l1 != None):
                sum1+= l1.val
                l1 = l1.next
            if(l2 != None):
                sum1+= l2.val
                l2 = l2.next
            sum1 += carry
            carry = sum1//10
            n = sum1%10

            n1 = ListNode(n)
            head.next = n1
            head = n1  

            sum1 = 0       
            
        return l3.next
