
# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution(object):
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root:
            return True
        def getLength(node):
            if not node:
                return 0
            l = getLength(node.left)
            r = getLength(node.right)
            return l + 1 if l > r else r + 1
        l = getLength(root.left)
        r = getLength(root.right)
        delta = abs(l - r)
        return self.isBalanced(root.left) and self.isBalanced(root.right) and delta <= 1  