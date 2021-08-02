class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) < 2:
            return len(nums)
        slow, fast = 2, 2
        while(fast < len(nums)):
            if (nums[fast] != nums[slow-2]):
                nums[slow] = nums[fast]
                slow += 1
            fast += 1
        
        return slow

nums = [1,1,1,2,2,3]
s = Solution()
l = s.removeDuplicates(nums)
for _ in range(l):
    print(nums[_])