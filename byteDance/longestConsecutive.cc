#include "head.h"
/*  Records the longest num in vector. Using hash 
    and some trick. */
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        unordered_set<int> num_set;
        for(auto& n:nums){
            num_set.insert(n);
        }
        int max_consecutive = 1;
        for(int i = 0; i < nums.size(); ++i){
            int x = nums[i];
            int cur_len = 1;
            if(num_set.find(x-1) != num_set.end()){
                continue;
            }
            // x is the start point
            while(num_set.find(++x) != num_set.end()){
                ++cur_len;
            }
            max_consecutive = std::max(cur_len, max_consecutive);
        }
        return max_consecutive;
    }
};