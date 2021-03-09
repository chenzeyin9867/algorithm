from collections import Counter
class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if not nums: return []
        num_dict = dict(Counter(nums))
        # print(num_dict)
        num_set = set(nums)
        sort_set = sorted(num_set)
        rs = []
        for i, x in enumerate(sort_set):
            if x > 0:
                break
            for li in range(i, len(sort_set)):
                y = sort_set[li]
                z = 0 - x - y
                if z < y: break
                if z in num_set:
                    tmp = [x, y ,z]
                    tmp_ = Counter(tmp)
                    flag = True
                    for t in tmp_.keys():
                        if tmp_[t] > num_dict[t]:
                            flag = False
                            break
                    if flag == True:
                        rs.append(tmp)                        
        return rs


if __name__ == "__main__":
    s = Solution()
    nums = [0,0,0]
    l = s.threeSum(nums)
    print(l)