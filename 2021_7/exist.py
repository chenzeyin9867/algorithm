class Solution(object):
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        h, w = len(board), len(board[0])
        visit = [[0 for _ in range(w)] for _ in range(h)] # whether visited in this term
        def inside(i, j):
            if (i >=0 and i < h) and (j >=0 and j < w):
                return True
            else:
                return False

        def recursive_exist(i, j, temp):
            if temp == word:
                return True
            if len(temp) == len(word):
                return False
            cur = len(temp)
            if inside(i,j):
                if word[cur] == board[i][j] and not visit[i][j]: # current char equals and not visited, recursive from four directins
                    visit[i][j] = 1
                    temp += word[cur]
                    #up 
                    if recursive_exist(i-1, j, temp):
                        return True
                    if recursive_exist(i+1, j, temp):
                        return True
                    if recursive_exist(i, j-1, temp):
                        return True
                    if recursive_exist(i, j+1, temp):
                        return True
                    temp = temp[:-1]
                    visit[i][j] = 0
                    return False
            return False


        for row in range(h):
            for col in range(w):
                temp = ""
                if recursive_exist(row, col, temp):
                    return True
        
        return False
    
board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
# word = "ABCCED"
word = "ABCB"
s = Solution()
print(s.exist(board, word))


