# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if not l1: return l2
        elif not l2: return l1
        head = ListNode(0) # init head, clip it when return 
        cur = head
        while(l1 or l2):
            if l1 and l2:
                if l1.val < l2.val:
                    cur.next = l1
                    cur = cur.next
                    l1 = l1.next
                else:
                    cur.next = l2
                    cur = cur.next
                    l2 = l2.next
            else:
                if l1:
                    cur.next = l1
                    break
                else:
                    cur.next = l2
                    break
        return head.next

