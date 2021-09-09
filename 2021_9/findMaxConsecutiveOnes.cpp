#include "head.h"
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int consecutiveCnt = 0;
        int curCnt = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1) {
                ++curCnt;
            }else{
                consecutiveCnt = curCnt > consecutiveCnt ? curCnt : consecutiveCnt;
                curCnt = 0;
            }
        }
        consecutiveCnt = curCnt > consecutiveCnt ? curCnt : consecutiveCnt;
        return consecutiveCnt;
    }
};