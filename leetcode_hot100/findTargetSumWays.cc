#include "head.h"
/* Give a vector of numbers and a target, get the number of 
   combination could results in target. */
class Solution {
public:
    int m_sum_;
    int findTargetSumWays(vector<int>& nums, int target) {
        // for each number, could use '-' or '+'
        m_sum_ = 0;
        dfs(nums, 0, target);
        return m_sum_;
    }

    /* idx means start from the idx, target means current
       distance to 0 */
    void dfs(vector<int> &nums, int idx, int target){
        if(target == 0 && idx == nums.size()){
            ++m_sum_;
            return;
        }
        if(idx >= nums.size()) return;
        // add '-' or '+' befor nums[idx]
        // first put '-'
        int cur = nums[idx];
        dfs(nums, idx + 1, target - cur);
        dfs(nums, idx + 1, target + cur);
        return;
    }
};

int main(){
    Solution s;
    vector<int> str{1, 1, 1, 1, 1};
    cout << "combination: " << s.findTargetSumWays(str, 3) << endl;
    return 0;
}