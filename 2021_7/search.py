class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: bool
        """
        def binaraySearch(nums, low, high, target): # assume nums[low, high] is in order, judge whether target is inside the nums[low, high]
            # if low == high:
                # return nums[low] == target
            while low <= high:
                mid = int((low + high)/2) 
                if nums[mid] == target:
                    return True
                elif nums[mid] > target:
                    high = mid -1
                elif nums[mid] < target:
                    low = mid + 1
            
            return False

        low = 0
        high = len(nums) - 1
        while low <= high:
            mid = int((low + high)/2)
            if nums[mid] == target:
                return True
            if nums[mid] == nums[low] and nums[mid] == nums[high]:
                low = low + 1
                high = high - 1
            elif nums[mid] >= nums[low]: # left part is in order
                if binaraySearch(nums, low, mid-1, target):
                    return True
                low = mid + 1
            # if nums[mid] <= nums[high]: # right is in order
            else: 
                if binaraySearch(nums, mid+1, high, target):
                    return True
                high = mid - 1

                # low = mid + 1
        
        return False


nums = [2,2,2,3,1]
target = 1
s = Solution()
print(s.search(nums, target))
