# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head or not head.next:
            return head
        ret = None
        prev = None
        slow = head
        fast = head.next
        while slow:
            if fast and fast.val == slow.val: # delete this node
                while fast and fast.val == slow.val:
                    fast = fast.next
                if not fast:
                    if prev:
                        prev.next = None
            else: # slow != fast , keep this node
                if not ret:
                    ret = slow
                    prev = slow
                else:
                    prev.next = slow
                    prev = slow
            slow = fast
            if fast:
                fast = fast.next

        return ret


s = Solution()
head = ListNode(1,ListNode(2,ListNode(3,ListNode(3,ListNode(4,ListNode(4,ListNode(5)))))))
ret = s.deleteDuplicates(head)
while ret:
    print(ret.val)
    ret = ret.next

    