# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        # use Pre-order to ?


        def recursiveSymmetric(left, right):
            if not left and not right:
                return True
            if not left or not right:
                return False
            if left.val != right.val:
                return False
            return recursiveSymmetric(left.right, right.left) and recursiveSymmetric(left.left, right.right)

        if not root:
            return True
        else:
            return recursiveSymmetric(root.left, root.right)

s = Solution()
head = TreeNode(1, left=TreeNode(2, TreeNode(3), TreeNode(4)), right=TreeNode(2, TreeNode(4), TreeNode(3)))
print(s.isSymmetric(head))