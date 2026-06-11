# Last updated: 6/11/2026, 11:25:50 AM
class LinkedList:
    def __init__(self, val=None):
        self.next = None
        self.val = val

class Solution:
    def findTheWinner(self, n: int, k: int) -> int:
        head = LinkedList(0)
        cur = head

        for i in range(1, n+1):
            cur.next = LinkedList(i)
            cur = cur.next

        head = head.next

        cur = head
        
        while(cur.next):
            cur = cur.next
        

        cur.next = head

        itr = head
        
        if(k==1):
            return n
        
        while(True):
            for i in range(k-2):
                itr = itr.next
            print("del",itr.next.val)
            itr.next = itr.next.next
            n = n-1
            if(n==1):
                break
            itr = itr.next
        print(itr.val)
        return itr.val
                
        
        
        