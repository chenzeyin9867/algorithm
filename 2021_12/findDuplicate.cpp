#include "head.h"
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int r = nums.front();
        for(int i = 1; i < nums.size(); ++i){
            r = r ^ nums[i];
            if(r == 0) {
                return nums[i];
            }
        }
        return 0;
    }
};