class Solution(object):
    """
    look for the needle in the haystack
    """
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        if not needle: return 0
        len1 = len(haystack)
        len2 = len(needle)
        i = 0
        while i < len1 - len2 + 1:
            if haystack[i:i + len2] == needle:
                return i
            i += 1
        return -1
        
s = Solution()
haystack = "a"
needle = "a"
print(s.strStr(haystack, needle))
