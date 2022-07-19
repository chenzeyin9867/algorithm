#include "head.h"
/*  Calculate the number of path sums = targetSum,
    The targetSum ranges from [-1000, 1000], so use
    an extra index to represent it */
class Solution
{
public:
    unordered_map<TreeNode *, vector<pair<long long, long long>>> sum_map;
    long long m_cnt_;
    long long m_target_;
    int pathSum(TreeNode *root, long long targetSum)
    {
        m_cnt_ = 0;
        m_target_ = targetSum;
        dfs(root);
        return m_cnt_;
    }

    /* Using post-order traversal */
    void dfs(TreeNode *node)
    {
        if (!node)
        {
            return;
        }
        dfs(node->left);
        dfs(node->right);
        // Calculate the number for node based on left and right child
        unordered_map<long long, long long> cnt_map;
        if (node->left)
        {
            auto relation_vector = sum_map[node->left];
            for (auto &pair_t : relation_vector)
            {
                long long sum = pair_t.first;
                long long cnt = pair_t.second;
                cnt_map[sum + node->val] += cnt;
            }
        }

        if (node->right)
        {
            auto relation_vector = sum_map[node->right];
            for (auto &pair_t : relation_vector)
            {
                long long sum = pair_t.first;
                long long cnt = pair_t.second;
                cnt_map[sum + node->val] += cnt;
            }
        }
        ++cnt_map[node->val]; // self
        vector<pair<long long, long long>> tmp_vector;
        for (auto &t : cnt_map)
        {
            auto p = make_pair(t.first, t.second);
            if (t.first == m_target_)
            {
                m_cnt_ += t.second;
            }
            tmp_vector.push_back(p);
        }
        sum_map[node] = tmp_vector;
    }
};