"""
Delete the N'th node from the end using only one pass
Idea:
    use two pointers which gaps N units, one to the end, one to the N'th from end 
"""

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        t = head
        length = 1
        while t.next:
            t = t.next
            length += 1
        if n == length:
            return head.next
        
        right = head
        left = head
        for _ in range(n):
            right = right.next
        while right.next:
            right = right.next
            left = left.next
        left.next = left.next.next
        return head



s = Solution()

head = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
head = ListNode(1)
n = 1
head = s.removeNthFromEnd(head, n)
while head:
    print(str(head.val) + '->')
    head = head.next