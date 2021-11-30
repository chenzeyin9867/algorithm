/**
 * @brief       return the maximal number of a sliding window
 * @author 		chenzeyin (chenzeyin9867@buaa.edu.cn)
 * @date		2021-11-30
 */
#include "head.h"
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // init the maps_
        for(int i = 0; i < k; ++i){
            ++maps_[nums[i]];
        }
        auto it = maps_.end();
        --it;
        result_.push_back(it->first);
        for(int i = 1; i + k <= nums.size(); ++i){
            int prev = nums[i-1];
            // pop out the prev in maps_
            if((--maps_[prev]) == 0){
                maps_.erase(prev);
            }
            ++maps_[nums[i + k - 1]];
            auto it = maps_.end();
            --it;
            result_.push_back(it->first);
        }
        return result_;
    }
private:
    map<int, int> maps_;
    vector<int> result_;
};

int main(){
    Solution s;
    vector<int> nums{1,3,-1,-3,5,3,6,7};
    vector<int> ret = s.maxSlidingWindow(nums, 3);
    printVector(ret);
    return 0;
}