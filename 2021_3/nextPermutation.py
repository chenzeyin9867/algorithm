class Solution(object):
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        if len(nums) == 0 or len(nums) == 1: return nums
        i = 0
        j = 1
        while j < len(nums):
            if nums[j] <= nums[j-1]:
                j += 1
            else:
                i = j
                j += 1
        if i == 0:
            nums[:] = nums[::-1]
        
        else:
            k = len(nums) -1
            while nums[k] <=  nums[i-1]:
                k -= 1
            t = nums[k]
            nums[k] = nums[i-1]
            nums[i-1] = t
            nums[i:] = nums[i:][::-1]
            return nums

s = Solution()
num = [1,5,1]
# nums = [2,2,2]
print(s.nextPermutation(num))

                