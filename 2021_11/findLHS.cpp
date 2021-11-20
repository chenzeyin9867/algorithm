/**
 * @file findLHS.cpp
 * @author chenzeyin (you@domain.com)
 * @brief  Harmonic Substring
 * @version 0.1
 * @date 2021-11-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "head.h"
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> num_map;
        for(auto const &t: nums){
            num_map[t]++;
        }
        int cur_result = 0;
        for(auto &key: nums){
            if(num_map.count(key+1)){
                cur_result = max(cur_result, num_map[key] + num_map[key+1]);
            }
        }
        return cur_result;
    }
};