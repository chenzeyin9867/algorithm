class Solution(object):
    numDict = {    '2':['a', 'b', 'c'],
                   '3':['d', 'e', 'f'],
                   '4':['g', 'h', 'i'],
                   '5':['j', 'k', 'l'],
                   '6':['m', 'n', 'o'],
                   '7':['p', 'q', 'r', 's'],
                   '8':['t', 'u', 'v'],
                   '9':['w', 'x', 'y', 'z']}
    retList = []

    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        cnt = [0] * 10
        curResult = ''
        strNum = digits
        numLen = len(strNum)
        if numLen == 0: return []
        if numLen == 1: return self.numDict[digits]
        firstNum = strNum[0]
        for i in (self.numDict[firstNum]):
            curResult += i
            self.processStr(curResult, strNum[1:])
            curResult = ''
        return self.retList
        
    def processStr(self, curResult, strs):
        if len(strs) == 1:
            for i in (self.numDict[(strs)]):
                self.retList.append(curResult + i)
        else:
            for i in (self.numDict[(strs[0])]):
                tmp = curResult
                tmp += i
                self.processStr(tmp, strs[1:])
                
        
            
            
        

s = Solution()

print(s.letterCombinations("22"))