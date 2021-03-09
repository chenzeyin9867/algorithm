class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        leftParam = "({["
        rightParam = ')}]'
        matchPairs = {')':'(', ']':'[', '}':'{'}
        stack = []
        for i in s:
            if i in leftParam:
                stack.append(i)
            else:
                if len(stack) == 0:return False
                if stack[-1] != matchPairs[i]: return False
                stack.pop()
        if len(stack) == 0:return True
        else: return False

s = Solution()
print(s.isValid('{[]}'))