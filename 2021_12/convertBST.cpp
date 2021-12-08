#include "head.h"
class Solution {
private:
    vector<TreeNode*> node_vector_;
public:

    TreeNode* convertBST(TreeNode* root) {
        dfs(root);
        int cur = 0;
        for(int i = 0; i < node_vector_.size(); ++i){
            cur += node_vector_[i]->val;
            node_vector_[i]->val = cur;
        }
        return root;
    }
    
    void dfs(TreeNode* node){
        if(!node){
            return;
        }
        dfs(node->right);
        node_vector_.push_back(node);
        dfs(node->left);
        return;
    }
};