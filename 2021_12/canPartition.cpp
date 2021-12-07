/**
 * @brief       can we partion the array into two subarray which sum equals
 * @author 		chenzeyin (chenzeyin9867@buaa.edu.cn)
 * @date		2021-12-07
 */
#include "head.h"
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // std::sort(nums.begin(), nums.end());
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0) return false;
        int half_sum = sum / 2;
        vector<vector<int>> dp(nums.size() + 1, vector<int>(half_sum + 1, 0));
        for(int i = 0; i < nums.size(); ++i){
            dp[i][0] = 1;
        }
        dp[0][nums[0]] = 1;
        
        for(int i = 1; i < nums.size(); ++i){
            for(int j = 1; j <= half_sum; ++j){
                if(j >= nums[i]){
                    dp[i][j] = (dp[i-1][j] || dp[i-1][j-nums[i]]);
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[nums.size() - 1][half_sum];
    }
};