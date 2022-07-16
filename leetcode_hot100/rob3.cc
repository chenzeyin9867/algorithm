#include "head.h"
/* All thd nodes are structured like a binary tree. */
class Solution {
public:
    int m_max_scores_;
    unordered_map<TreeNode*, int> m_score_map_;
    int rob(TreeNode* root) {
        // m_max_scores_ = 0;
        return dfs(root);
    }

    int getScore(TreeNode *node){
        if(m_score_map_.find(node) != m_score_map_.end()){
            return m_score_map_[node];
        }
        return dfs(node);
    }

    // Return the maximal scores from the node
    int dfs(TreeNode *node){ 
        if(!node){
            return 0;
        }
        // If rob node
        int rob_score = node->val;
        if(node->left){
            rob_score += getScore(node->left->left) + getScore(node->left->right);
        }
        if(node->right){
            rob_score += getScore(node->right->left) + getScore(node->right->right);
        }

        // Not rob node
        int no_rob = getScore(node->left) + getScore(node->right);
        m_score_map_[node] = std::max(rob_score, no_rob);
        return std::max(rob_score, no_rob);
    }
};