#include "head.h"
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3) return false;
        vector<int> tmp;
        return dfs(nums, 0, 3, tmp);
    }

    bool dfs(vector<int>& nums, int idx, int left, vector<int> &tmp){
        if(left == 0) return true;
        if(idx >= nums.size()) return false;
        bool r1 = false, r2 = false;
        if(tmp.empty() || nums[idx] > tmp.back()){
            tmp.push_back(nums[idx]);
            r1 = dfs(nums, idx+1, left - 1, tmp);
            tmp.pop_back(); 
        }
        return r1 || dfs(nums, idx + 1, left, tmp);
    }
};