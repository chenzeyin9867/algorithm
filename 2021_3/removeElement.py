class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        if len(nums) == 0: return 0
        left = 0
        rigth = 0
        while rigth < len(nums):
            if  nums[rigth] != val:
                nums[left] = nums[rigth]
                left += 1
                rigth += 1
            else:
                rigth += 1
        
        return left

s = Solution()
nums = [0,1,2,2,3,0,4,2]
nums = [1]
val = 1
for _ in range(s.removeElement(nums, val)):
    print(nums[_], end=" ")
print("")