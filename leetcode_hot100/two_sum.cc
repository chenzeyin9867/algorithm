#include "head.h"
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> m_map;
        for(int i = 0; i < nums.size(); ++i){
            if(m_map.find(target - nums[i]) != m_map.end()){
                result.push_back(m_map[target - nums[i]]);
                result.push_back(i);
                return result;
            }
            m_map[nums[i]] = i;
        }
        return result;
    }
};