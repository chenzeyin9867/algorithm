#include "head.h"
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        unordered_set<int> num_set;
        for(const int &t : nums){
            num_set.insert(std::move(t));
        }
        int maxLength = 1;
        for(const int &t : nums){
            if(num_set.count(t-1) == 0){
                int curLength = 1;
                int start = t+1;
                while(num_set.count(start)){
                    ++curLength;
                    ++start;
                }
                maxLength = curLength > maxLength ? curLength: maxLength;
            }
        }
        return maxLength;
        
    }
};