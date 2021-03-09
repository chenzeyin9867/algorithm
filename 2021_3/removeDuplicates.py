class Solution(object):
    """
    use two pointers, left represent the current number, rigth iterate the list to find the different numvers
    """
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0: return 0
        if len(nums)== 1:
            return 1
        left = 0
        right = 0
        while right < len(nums):
            while nums[right] == nums[left]:
                right += 1
                if right >= len(nums):
                    break
            if right < len(nums):
                left += 1
                nums[left] = nums[right]
        
        return left + 1

s = Solution()
nums = [0,0,1,1,1,2,2,3,3,4]
nums = [1,1,2]
n = s.removeDuplicates(nums)
for _ in range(n):
    print(nums[_], end=" ")
print("")

        