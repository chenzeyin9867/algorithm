#include "head.h"
/* A robber cannot rob a continuous houses */
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> profits(nums.size(), 0);
        if(nums.size() <= 0) return 0;
        profits[0] = std::max(nums[0], 0);
        for(int i = 1; i < nums.size(); ++i){
            int no_rob = profits[i-1];
            int rob = nums[i] + ( i >= 2 ? profits[i-2] : 0);
            profits[i] = std::max(no_rob, rob); 
        }
        return profits.back();
    }
};