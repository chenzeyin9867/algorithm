#include "head.h"
class Solution {
public:
    vector<TreeNode*> m_path1_;
    vector<TreeNode*> m_path2_;
    vector<TreeNode*> m_cur_path_;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        // Compare the m_path1_ and m_path2_ to find the last common node;
        cout << "End the DFS" << endl;
        int l = 0, r = 0;
        while(l < m_path1_.size() && r < m_path2_.size()){
            if(m_path1_[l] == m_path2_[r]){
                ++l;
                ++r;
            }else{
                break;
            }
        }
        return m_path1_[l-1];
    }

    void dfs(TreeNode* node, TreeNode* p, TreeNode* q){
        if(!node) return;
        m_cur_path_.push_back(node);
        if(node == p){
            m_path1_ = m_cur_path_;
        }else if(node == q){
            m_path2_ = m_cur_path_;
        }
        dfs(node->left, p, q);
        dfs(node->right, p, q);
        m_cur_path_.pop_back();
        return;
    }
};