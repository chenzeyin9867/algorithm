#include "head.h"
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        int length = 1;
        int prev = 0;
        int cur  = 1;
        while(cur < nums.size()){
            while(cur < nums.size() && nums[cur] > nums[cur-1]){
                ++cur;
            }
            length = (cur - prev) > length ? (cur - prev) : length;
            prev = cur;
            ++cur;
        }
        return length;
    }
};