#include "head.h"

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        /* windows store the idx of num in an ascending order */
        std::deque<int> windows;
        vector<int> result;
        for(int i = 0; i < nums.size(); ++i){
            /* Delete all the number less than nums[i] in queue */
            while(!windows.empty() && nums[i] >= nums[windows.back()]){
                windows.pop_back();
            }
            windows.push_back(i);
            if(i >= k - 1){
                if(i - windows.front() >= k){
                    windows.pop_front();
                }
                result.push_back(nums[windows.front()]);
            }
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<int> input {1, 3, -1, -3, 5, 3, 6, 7};
    auto ret = s.maxSlidingWindow(input, 3);
    printVector(ret);
    return 0;
}