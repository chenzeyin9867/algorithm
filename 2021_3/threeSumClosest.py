"""
This method get the closest sum of three numbers as the target
"""
class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        # sort the list first
        sortedNum = sorted(nums)
        numLen = len(nums)
        # define three points, and just iterate the pa, the pb and pc use the classic two pointers's theory
        pa = 0
        pb = 1
        pc = numLen -1
        closestSum = sortedNum[pa] + sortedNum[pb] + sortedNum[pc] 
        for pa in range(numLen - 1):
            pb = pa + 1
            pc = numLen - 1
            while pb < pc:
                s = getSum(sortedNum, pa, pb, pc)
                if abs(s - target) < abs(target - closestSum) : closestSum = s
                if s > target:
                    pc -= 1
                else:
                    pb += 1
        return closestSum
                
            
        
def getSum(nums, a, b, c):
    return nums[a] + nums[b] + nums[c]
        
s = Solution()
target = 1
nums = [0, 2, 1, -3]
print(s.threeSumClosest(nums, target))