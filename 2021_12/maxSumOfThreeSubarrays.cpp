/**
 * @brief       Given an integer array nums and an integer k, find three non-overlapping subarrays of length k with maximum sum
 *              first compute a vector which contains three continus sub-array sum
 * @author 		chenzeyin (chenzeyin9867@buaa.edu.cn)
 * @date		2021-12-08
 */
#include "head.h"
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> sum_arr(nums.size() - k + 1, 0);
        cout << "Begin sum " << endl;

        for(int i = 0; i < sum_arr.size(); ++i){
            for(int j = 0; j < k; ++j){
                sum_arr[i] += nums[i + j];
            }
        }

        for(auto &a: sum_arr){
            cout << a << " ";
        }
        // choose three num in sum_arr, each must gap k
        vector<vector<int>> dp(sum_arr.size(), vector<int>(4, 0));
        vector<vector<int>> record(sum_arr.size(), vector<int>(4, 0));
        // dp[i][j] means the from 0-i choose j sub arr can return how much
        int cur_max = -1;
        for(int i = 0; i < sum_arr.size(); ++i){
            // dp[i][1] = current max
            if(sum_arr[i] > cur_max) // take this
            {
                record[i][1] = 1;
            }
            cur_max = std::max(cur_max, sum_arr[i]);
            dp[i][1] = cur_max;
        }



        for(int i = 2; i <= 3; ++i){
            for(int j = 1; j < sum_arr.size(); ++j){
                if(j >= k){
                    dp[j][i] = std::max(dp[j-1][i], dp[j-k][i-1] + sum_arr[j]);
                    if(dp[j-1][i] < dp[j-k][i-1] + sum_arr[j]) record[j][i] = 1;

                }else{
                    dp[j][i] = std::max(dp[j-1][i], sum_arr[j]);
                    if(dp[j-1][i] < sum_arr[j]){
                        record[j][i] = 1;
                    }
                }
            }
        }

        for(int i = 1; i < sum_arr.size(); ++i){
            for(int j = 2; j <= 3 && j <= i; ++j){
                if(i >= k){
                    if(dp[i-1][j] < dp[i-k][j-1] + sum_arr[i]){
                        record[i][j] = 1;
                    }
                    dp[i][j] = std::max(dp[i-1][j], dp[i - k][j - 1] + sum_arr[i]);
                }else{
                    if(dp[i-1][j] < sum_arr[i]){
                        record[i][j] = 1;
                    }
                    dp[i][j] = std::max(dp[i-1][j], sum_arr[i]);
                }
                
            }
        }
        vector<int> result;
        
        int r = 3;
        int end = record.size() - 1;
        while(r > 0){
            
            while(record[end][r] == 0){
                --end;
            }
            result.insert(result.begin(), end);
            --r;
            end = end - k;
        }
        cout << endl;
        cout << "The sum is " << dp[sum_arr.size() - 1][3] << endl;
        return result;
    }
};