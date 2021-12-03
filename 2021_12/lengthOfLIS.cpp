#include "head.h"
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, 1);
        dp[0] = 0;
        nums.insert(nums.begin(), 0);
        dp[1] = 1;
        int max_length = 1;
        for(int outer = 2; outer < nums.size(); ++outer){
            int cur = 1;
            for(int inner = 1; inner < outer; ++inner){
                // dp[outer] = max(dp[inner] + 1)
                if(nums[outer] > nums[inner]){
                    cur = std::max(cur, dp[inner] + 1);
                }
            }
            dp[outer] = cur;
            max_length = std::max(max_length, cur);
            // cout << outer << " :" << dp[outer] << endl;
        }
        return max_length;
    }
};