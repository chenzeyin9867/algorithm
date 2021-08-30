#include "head.h"
class NumArray {
public:
    NumArray(vector<int>& nums) {
        sum.emplace_back(nums[0]);
        for(int i = 1; i < nums.size(); i++){
            sum.emplace_back(sum.back() + nums[i]);
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0) return sum[right];
        else return sum[right] - sum[left - 1];
    }
public:
    vector<int> sum;
};