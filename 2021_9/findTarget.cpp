#include "head.h"
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> numSet;
        return dfs(root, k, numSet);
    }

    bool dfs(TreeNode* node, int val, unordered_set<int>& numSet){
        if(!node) return false;
        bool b1 = numSet.count(val - node->val);
        if(b1) return true;
        numSet.emplace(node->val);
        bool b2 = dfs(node->left, val, numSet);
        bool b3 = dfs(node->right, val, numSet); 
        return b2 | b3;
            
    }
};