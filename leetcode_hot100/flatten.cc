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
    void flatten(TreeNode *root)
    {
        /* Not a inplace algorithm, save all the nodes first */
        vector<TreeNode *> m_list;
        dfs(root, m_list);
        if (m_list.size() <= 1)
        {
            return;
        }
        for (int i = 0; i < m_list.size() - 1; ++i)
        {
            m_list[i]->left = nullptr;
            m_list[i]->right = m_list[i + 1];
        }
        return;
    }

    void dfs(TreeNode *node, vector<TreeNode *> &m_list)
    {
        if (!node)
            return;
        m_list.push_back(node);
        dfs(node->left, m_list);
        dfs(node->right, m_list);
        return;
    }
};