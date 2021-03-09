class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        romanDict = {"I":1, "V":5, "X":10, "L":50, "C":100, "D":500, "M":1000}
        if len(s)==1:
            return romanDict[s]
        rt = 0
        pt = 0
        strLen = len(s)
        while pt < strLen:
            cur = s[pt]
            if cur == 'I':
                if pt+1 < strLen:
                    if s[pt+1] == 'V':
                        rt += 4
                        pt += 2
                    elif s[pt+1] == 'X':
                        rt += 9
                        pt += 2
                    else:
                        rt += romanDict[cur]
                        pt += 1
                else:
                    rt += romanDict[cur]
                    pt += 1
            elif cur == 'X':
                if pt+1 < strLen:
                    if s[pt+1] == 'L':
                        rt += 40
                        pt += 2
                    elif s[pt+1] == 'C':
                        rt += 90
                        pt += 2
                    else:
                        rt += romanDict[cur]
                        pt += 1
                else:
                    rt += romanDict[cur]
                    pt += 1
            elif cur == 'C':
                if pt+1 < strLen:
                    if s[pt+1] == 'D':
                        rt += 400
                        pt += 2
                    elif s[pt+1] == 'M':
                        rt += 900
                        pt += 2
                    else:
                        rt += romanDict[cur]
                        pt += 1
                else:
                    rt += romanDict[cur]
                    pt += 1
            
            else:
                rt += romanDict[cur] 
                pt += 1
        return rt

s = Solution()
print(s.romanToInt('MCMXCIV'))