class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        longestPrefix = ''
        prefixLength = 1000
        if len(strs) == 0:
            return ""
        axisStr = strs[0]
        for i in range(1, len(strs)):
            subStr = strs[i]
            commonLen = commonPrefix(axisStr, subStr)
            if commonLen < prefixLength:
                prefixLength = commonLen
        return axisStr[0:prefixLength]
    


def commonPrefix(str1, str2):
    """
    get the length of the common prefix of two str
    """
    commonLen = 0
    len1 = len(str1)
    len2 = len(str2)
    if not str1 or not str2:
        return 0
    if str1[0] != str2[0]:
        return 0
    pt1 = 0
    pt2 = 0
    while pt1 < len(str1) and pt2 < len(str2) :
        if str1[pt1] == str2[pt2]:
            commonLen += 1
            pt1 += 1
            pt2 += 1
        else:
            break
    return commonLen
            
    
s = Solution()
strs = ["",""]
print(s.longestCommonPrefix(strs))
