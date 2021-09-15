#include "head.h"
class Solution {
public:
    int findTilt(TreeNode* root) {
        if(!root) return 0;
        dfs(root);
        return sumTilt;
    }

    int dfs(TreeNode* node){
        if(!node) return 0;
        int lsum = 0;
        int rsum = 0;
        if(!node->left) lsum = 0;
        else lsum = dfs(node->left);
        if(node->right) rsum = dfs(node->right);
        sumTilt += abs(lsum - rsum);
        return lsum + rsum + node->val;
    }

    int sumTilt = 0;
};