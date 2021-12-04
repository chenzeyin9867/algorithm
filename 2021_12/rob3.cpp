/**
 * @brief       given a tree, we can not steel two neighbour, ret the maximal money we can steel
 * @author 		chenzeyin (chenzeyin9867@buaa.edu.cn)
 * @date		2021-12-04
 */
#include "head.h"
class Solution {
public:
    unordered_map <TreeNode*, int> f, g;

    void dfs(TreeNode* node) {
        if (!node) {
            return;
        }
        dfs(node->left);
        dfs(node->right);
        f[node] = node->val + g[node->left] + g[node->right];
        g[node] = max(f[node->left], g[node->left]) + max(f[node->right], g[node->right]);
    }

    int rob(TreeNode* root) {
        dfs(root);
        return max(f[root], g[root]);
    }
};
