#include "head.h"
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = nums.front();
        for(int i = 1; i < nums.size(); ++i){
            x = x ^ nums[i];
        }
        return x;
    }
};