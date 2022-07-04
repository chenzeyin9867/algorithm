#include "head.h"
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int ptr = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                swap(nums[i], nums[ptr]);
                ++ptr;
            }
        }
        for (int i = ptr; i < n; ++i) {
            if (nums[i] == 1) {
                swap(nums[i], nums[ptr]);
                ++ptr;
            }
        }
    }
};

int main(){
    Solution s;
    vector<int> input {2, 0, 2, 1, 1, 0};
    s.sortColors(input);
    for(auto &t : input){
        std::cout << t << " ";
    }
    std::cout << std::endl;
    return 0;
}