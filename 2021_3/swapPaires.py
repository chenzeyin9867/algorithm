# Definition for singly-linked list.

"""
this method swap the two numbers of the link
"""
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head: return head
        if not head.next: return head # only one node in the list
        tmp = head
        prev = None
        while tmp:
            if not tmp.next:
                return head
            next1 = tmp.next
            next2 = next1.next
            next1.next = tmp
            tmp.next = next2
            if not prev:
                head = next1
            else:
                prev.next = next1
            prev = tmp
            tmp = tmp.next
                
        
        return head

s = Solution()
head = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
# head = ListNode(1)
head = s.swapPairs(head)
while head:
    print(head.val)
    head = head.next
