#include "head.h"
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int acc = std::accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(nums.size(), vector<int>(2 * acc + 1, 0));
        if(target > acc || target < -acc){
            return 0;
        }
        // upper version responds to minus version
        // cout << "begin" << endl;
        dp[0][nums[0] + acc] += 1;
        dp[0][acc - nums[0]] += 1;
        
        // cout << "OK" << endl;
        for(int i = 1; i < nums.size(); ++i){
            for(int j = 0; j <= 2 * acc; ++j){
                // [acc + 1, 2*acc] corresponding to [-acc, -1]
                if(j - nums[i] >= 0) dp[i][j] += dp[i-1][j-nums[i]];
                if(j + nums[i] <= 2 * acc) dp[i][j] += dp[i-1][j + nums[i]];

            }
        }
        return dp[nums.size() - 1][target + acc];
        
    }
};