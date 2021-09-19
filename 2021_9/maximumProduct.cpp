#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        if(nums.size() == 3) return nums[0]*nums[1]*nums[2];
        sort(nums.begin(), nums.end());
        int num1 = nums[0] * nums[1] * nums[2];
        int num2 = nums[0] * nums[1] * nums.back();
        int num3 = nums[0] * nums.back() * nums[nums.size()-2];
        int num4 = nums.back() * nums[nums.size() - 2] * nums[nums.size() - 3];
        int maximal = max(max(num1, num2), max(num3, num4));
        return maximal;
    }
};