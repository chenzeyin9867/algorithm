#include "head.h"
/* Return the longest path between two leaf nodes */
class Solution {
public:
    int m_max_diameter_;
    int diameterOfBinaryTree(TreeNode* root) {
        m_max_diameter_ = 0;
        dfs(root);
        return m_max_diameter_;
    }

    /* return the longest path to leaf node from node */
    int dfs(TreeNode *node){
        if(!node) return 0;
        int l = dfs(node->left);
        int r = dfs(node->right);
        m_max_diameter_ = std::max(m_max_diameter_, l + r);
        return std::max(l, r) + 1;
    }
};