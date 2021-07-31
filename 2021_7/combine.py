
class Solution(object):
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
        ret = []
        def add(cur, n, temp): # cur represent current point, temp means current list
            if len(temp) == k:
                ret.append(list(temp))
                return
            if cur > n:
                return
            temp.append(cur)
            add(cur+1, n, temp)
            temp.remove(cur)
            add(cur+1, n, temp)

        l = [i+1 for i in range(n)]
        add(1, n, [])
        return ret

s = Solution()
ret = s.combine(4, 2)
for t in ret:
    print("[", end='')
    print(t , end="")
    print("]")
    # print("]")

