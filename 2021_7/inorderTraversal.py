# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution(object):
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        ret = []
        def ios(root):
            if not root:
                return 
            ios(root.left)
            ret.append(root.val)
            ios(root.right)
            # self.ios(root)
        ios(root)
        return ret



        
s = Solution()
root = TreeNode(val=1, right=TreeNode(val=2, left=TreeNode(val=3)))
# root = None
ret = s.inorderTraversal(root)
for i in ret:
    print(i)
