import numpy as np
class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows == 1:
            return s
        strLen = len(s)
        # rMatrix = np.str([['']*1000 for i in range(numRows)])
        rMatrix = [['']*1000 for i in range(numRows)]
        rowP = 0
        colP = 0
        cnt = 0
        while cnt < strLen:
            if colP % (numRows -1) == 0:
                if rowP < numRows:
                    rMatrix[rowP][colP] = s[cnt]
                    rowP += 1
                    cnt += 1
                else:
                    rowP -= 2
                    colP += 1
            else:
                rMatrix[rowP][colP] = s[cnt]
                colP += 1
                rowP -= 1
                cnt += 1
        rstr = ''
        for i in range(numRows):
            for j in range(colP+1):
                if rMatrix[i][j]:
                    rstr += rMatrix[i][j]
        return rstr
            
        
s = Solution()
str1 = 'A'
numRows = 1
result = s.convert(str1,numRows)
print(result)