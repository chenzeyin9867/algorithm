#include "head.h"
/* Find the Longest Increasing String */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        /* use an array to store the LFS num ends with idx */
        vector<int> lfs(nums.size() + 1, 0);

        lfs[0] = 1;
        int max_lfs = 1;
        for(int i = 1; i < nums.size(); ++i){
            /* iterator from 0 to i - 1 */
            for(int j = 0; j < i; ++j){
                lfs[i] = std::max(lfs[i], 
                    nums[j] < nums[i] ? lfs[j] + 1 : 1);
            }

            /* we can optimize this period using binary search */
            max_lfs = std::max(max_lfs, lfs[i]);
        }
        return max_lfs;
    }
};