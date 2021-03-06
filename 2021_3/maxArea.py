class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        listLen = len(height)
        maxArea = 0
        width = 0
        left = 0
        right = listLen - 1
        leftLength = height[left]
        rightLength = height[right]
        if listLen == 2:
            return min(leftLength, rightLength)
        while left < right:
            curArea = min(leftLength, rightLength) * (right - left)
            if curArea > maxArea:
                maxArea = curArea
            if leftLength < rightLength: # left is the shorter line, then the left point keeps going right
                while left < right and height[left] <= leftLength:
                    left += 1
                if left < right:
                    leftLength = height[left]
            else:
                while left < right and height[right] <= rightLength:
                    right -= 1
                if left < right:
                    rightLength = height[right]
        
        return maxArea

s = Solution()
height = [1,2,1]
d = s.maxArea(height)
print(d)
# print(s.maxArea(height))
                