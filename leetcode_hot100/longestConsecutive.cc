#include "head.h"

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        /* Use the unordered_set to delete the duplicated num */
        for (const int& num : nums) {
            num_set.insert(num);
        }
        int longest_list = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(num_set.find(nums[i]-1) != num_set.end()){
                /* If x-1 exists, no need to search from x */
                continue; 
            }
            /* Search from x until no consecutive */
            int cur = 1;
            while(num_set.find(nums[i]+cur) != num_set.end()){
                ++cur;
            }
            longest_list = std::max(longest_list, cur);
        }
        return longest_list;
    }
};