# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution(object):
    def findSecondMinimumValue(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        # if self.min == -1:
        #     self.min = root.val
        self.min = root.val
        self.secondMin = -1
        self.dfs(root)
        if self.min == self.secondMin:
            return -1
        else:
            return self.secondMin
    
        
    
    def dfs(self, node):
        if node.val > self.min:
            if self.secondMin == -1:
                self.secondMin = node.val
            elif node.val < self.secondMin:
                self.secondMin = node.val
            # self.secondMin = node.val 
        if node.left:
            self.dfs(node.left)
        if node.right:
            self.dfs(node.right)
        
            

s = Solution()
root = TreeNode(2, left=TreeNode(2), right=TreeNode(5, left=TreeNode(5), right=TreeNode(7)))
print("Hello word")
print(s.findSecondMinimumValue(root))
