#include "head.h"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int m_prev = -1;
    bool firstNode = true;
    bool isValidBST(TreeNode *root)
    {
        return dfs(root);
    }

    bool dfs(TreeNode *node)
    {
        if (!node)
            return true;
        bool ret1 = dfs(node->left);
        if (firstNode)
        {
            firstNode = false;
            m_prev = node->val;
        }
        else
        {
            if (m_prev >= node->val)
                return false;
            m_prev = node->val;
        }
        return ret1 && dfs(node->right);
    }
};