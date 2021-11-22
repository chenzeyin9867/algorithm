/**
 * @file		maxProduct.cpp
 * @brief       find the maximum product subarray
 * @author 		chenzeyin (chenzeyin9867@buaa.edu.cn)
 * @date		2021-11-22
 * @copyright	Copyright (c) 2021  chenzeyin9867
 */



/**
 * @brief This brute-force takes O(n^2) 
 */
#include "head.h"
// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         // if(nums.size() == 0) reti
//         if(nums.size() == 1) return nums.front();
//         int max_product = 0;
//         for(int i = 0; i <= nums.size() - 1; ++i){
//             int cur = 1;
//             for(int j = i; j < nums.size(); ++j){
//                 cur = cur * nums[j];
//                 max_product = max(cur, max_product);
//             }
//         }
//         return max_product;
//     }
// };

/**
 * @brief DP can give a O(n) alogrithm
 */
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector <int> maxF(nums), minF(nums);
        for (int i = 1; i < nums.size(); ++i) {
            maxF[i] = max(maxF[i - 1] * nums[i], max(nums[i], minF[i - 1] * nums[i]));
            minF[i] = min(minF[i - 1] * nums[i], min(nums[i], maxF[i - 1] * nums[i]));
        }
        return *max_element(maxF.begin(), maxF.end());
    }
};

