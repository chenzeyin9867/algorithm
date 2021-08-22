#include "head.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0, high = numbers.size() - 1;
        while (low < high) {
            int sum = numbers[low] + numbers[high];
            if (sum == target) {
                return {low + 1, high + 1};
            } else if (sum < target) {
                ++low;
            } else {
                --high;
            }
        }
        return {-1, -1};
    }
};

int main(){
    Solution s;
    vector<int> nums{2,7,11,15};
    int target = 13;
    vector<int> r = s.twoSum(nums, target);
    printVector(r);
    return 0;
}