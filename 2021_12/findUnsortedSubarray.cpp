#include "head.h"
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sorted_array = nums;
        std::sort(sorted_array.begin(), sorted_array.end()); // in-order
        int l = 0, r = nums.size() - 1;
        while(l < nums.size() && nums[l] == sorted_array[l]){
            ++l;
        }
        while(r > 0 && nums[r] == sorted_array[r]){
            --r;
        }
        if(l > r) return 0;
        int len_forward = (r - l + 1);
        

        
        return len_forward;
    }
};