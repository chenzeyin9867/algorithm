#include "head.h"
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> q; // stores the idx of the num
        for(int i = 0; i < nums.size(); ++i){
            while(!q.empty() && nums[q.back()] <= nums[i]){
                    q.pop_back();
                }
            q.push_back(i);
            // Pop out those out of range
            if(!q.empty() && q.front() + k - 1 < i){
                q.pop_front();
            }
            
            if(i >= k-1){
                result.push_back(nums[q.front()]);
            }
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<int> input = {1,3,-1,-3,5,3,6,7};
    auto vec = s.maxSlidingWindow(input, 3);
    printVector(vec);
    return 0;
}