"""
This method compute the 4 nums, use the classic two-pointers
time-somplexity O(n3)
"""
from collections import Counter
class Solution(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        # nums = sorted(nums)
        indexDict = dict(Counter(nums))
        nums = sorted(set(nums))
        returnList = []
        # print(indexDict)
        for i in range(len(nums)):
            for j in range(i, len(nums)):
                left = j # left pointer
                right = len(nums) - 1 # right pointer
                while left <= right:
                    if nums[i] + nums[j] + nums[left] + nums[right] == target:
                        returnList.append([nums[i], nums[j], nums[left], nums[right]])
                        left += 1
                        right -= 1
                    elif nums[i] + nums[j] + nums[left] + nums[right] < target:
                        left += 1
                    else:
                        right -= 1
        ret = []
        for l in returnList:
            t = dict(Counter(l))
            flag = True
            for k in t.keys():
                if t[k] > indexDict[k]:
                    flag = False
                    break
            if flag == True:
                ret.append(l)           
        return ret

s = Solution()
nums = [1,0,-1,0,-2,2]
target = 0
print(s.fourSum(nums, target))