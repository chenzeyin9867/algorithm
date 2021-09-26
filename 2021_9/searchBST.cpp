#include "head.h"
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        return dfs(root, val);
    }
    TreeNode* dfs(TreeNode* node, int & val){
        if(!node) return nullptr;
        if(val == node->val) return node;
        else return val < node->val ? dfs(node->left, val) : dfs(node->right, val); 
    }
};