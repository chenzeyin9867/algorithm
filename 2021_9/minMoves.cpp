#include "head.h"
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int movCnt = 0;

        int min = nums[0];
        for(int i = 0; i < nums.size(); i++){
            int delta = 0;
            if(min > nums[i]){
                delta = (min - nums[i])*(i);
                min = nums[i];
            }
            movCnt += (nums[i] - min) + delta;
        }
        return movCnt;
    }
};