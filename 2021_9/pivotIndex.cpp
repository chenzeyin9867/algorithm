#include "head.h"
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // unordered_map<int, int> numMap;
        for(int i = 0; i < nums.size(); ++i){
            if(i == 0) {
                nums[i] = nums[i];
            }
            else{
                nums[i] = nums[i] + nums[i-1];
            }
            // numMap.insert(nums[i]);
            // numMap[nums[i]] = i;
        }
        int sum = 0;
        int acc = nums.back();
        if(nums.size() > 1 && acc == nums[0]) return 0;
        for(int i = 0; i + 1 < nums.size(); ++ i){
            if(nums[i] == acc - nums[i+ 1]){
                return i+1;
            }
        }
        return -1;
    }
};