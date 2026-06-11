# Last updated: 6/11/2026, 11:38:23 AM
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if(lists == []):
            return
        while(len(lists)>1):
            mergedlists = []
            for i in range(0,len(lists),2):
                list1 = lists[i]
                list2 = lists[i+1] if i+1<len(lists) else None
                mergedlists.append(self.merge2lists(list1,list2))
            lists = mergedlists
        return lists[0]

    def merge2lists(self, list1, list2):
        dummy = ListNode()
        curr = dummy
        l1 = list1
        l2 = list2
        while(l1 and l2):
            if(l1.val<l2.val):
                curr.next = l1
                l1 = l1.next
                curr = curr.next
            else:
                curr.next = l2
                l2 = l2.next
                curr = curr.next
        if(l1):
            curr.next = l1
        if(l2):
            curr.next = l2
        return dummy.next

