/**
 * @file		rob.cpp
 * @brief 
 * @author 		chenzeyin (chenzeyin9867@buaa.edu.cn)
 * @date		2021-11-23
 * @copyright	Copyright (c) 2021  chenzeyin9867
 */

#include "head.h"
class Solution {
public:
    // int rob(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<vector<int>> dp(n,  {0, 0}); // two int represents whether takes this one
    //     dp[0][0] = 0;
    //     dp[0][1] = nums[0];
    //     for(int i = 1; i < nums.size(); ++i){
    //         // take this, then skip last one
    //         dp[i][1] =  nums[i] + dp[i-1][0];
    //         dp[i][0] =  max(dp[i-1][0], dp[i-1][1]);
    //     }
    //     return max(dp[n-1][0], dp[n-1][1]);
    // }
    int rob(vector<int>&nums){
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        for(int i = 1; i < n; ++i){
            if(i >= 2)
                dp[i] = max(dp[i-1], nums[i] + dp[i - 2]);
            else
                dp[i] = max(dp[i-1], nums[i]);
        }
        return dp[n-1];
    }
};