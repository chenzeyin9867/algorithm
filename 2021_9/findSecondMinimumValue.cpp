#include "head.h"
class Solution {
public:
    vector<int> nums;
    int findSecondMinimumValue(TreeNode* root) {
        dfs(root);
        sort(nums.begin(), nums.end());
        if(nums.size() <= 1) return -1;
        int minimal = nums[0];
        int index = 0;
        while(nums[index] == minimal){
            ++index;
        }
        if(index >= nums.size()) return -1;
        return nums[index];
    }
    void dfs(TreeNode* node){
        if(!node) return;
        nums.emplace_back(node->val);
        dfs(node->left);
        dfs(node->right);
    }
};