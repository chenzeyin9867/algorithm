# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        l = []
        for _ in lists:
            l.extend(_)
        l = sorted(l)
        head = ListNode(0)
        tmp = head
        for t in l:
            cur = ListNode(t)
            tmp.next = cur
            tmp = tmp.next
        return head.next

s = Solution()
lists = [[1,4,5],[1,3,4],[2,6]]
head = s.mergeKLists(lists)
while head:
    print(head.val)
    head = head.next

            
        