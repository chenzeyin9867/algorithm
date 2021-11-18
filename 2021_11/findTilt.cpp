#include "head.h"
class Solution {
public:
    vector<int> tilts;
    int findTilt(TreeNode* root) {
        int sum = 0;
        dfs(root, sum);
        return accumulate(tilts.begin(), tilts.end(), 0);
    }

    void dfs(TreeNode* node, int &sum){
        /* 
         * sum represents the total return by this node 
         *
         */
        if(!node) {
            sum = 0;
            return;
        }
        if(!node->left && !node->right) // leaf
        {
            sum += node->val;
        }
        int leftSum = 0, rightSum = 0;
        if(node->left) // handle left sub Tree
        {
            dfs(node->left, leftSum);
        }
        if(node->right){
            dfs(node->right, rightSum);
        }
        sum = leftSum + rightSum + node->val;
        tilts.push_back(abs(leftSum - rightSum));
        return;
    }
};