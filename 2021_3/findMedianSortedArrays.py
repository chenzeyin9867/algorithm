class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        len1 = len(num1)
        len2 = len(num2)
        if len1 == 0 and len2 ==0:
            return 0
        elif len1 ==0:
            if len2 % 2 == 0:
                mid = len2 / 2 -1
                return (num2[mid] + num2[mid+1]) / 2.0
            else:
                return num2[len2 / 2]
        elif len2 == 0:
            if len1 % 2 == 0:
                mid = len1 / 2 -1
                return (num1[mid] + num1[mid+1] / 2.0)
            else:
                return num1[len1/2] * 1.0
        while len1 > 0 or len2 >0:
            
            