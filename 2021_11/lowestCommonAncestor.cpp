/**
 * @brief       record two paths, and find the loweset Common Ancestor
 * @author 		chenzeyin (chenzeyin9867@buaa.edu.cn)
 * @date		2021-11-28
 */
#include "head.h"
class Solution {
vector<TreeNode*> path_;
vector<TreeNode*> p1_;
vector<TreeNode*> p2_;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        // reverse the two path, and find the first common ancestor;
        for(auto t: p1_){
            cout << "->" << t->val;
        }
        cout << endl;
        for(auto t: p2_){
            cout << "->" << t->val;
        }
        reverse(p1_.begin(), p1_.end());
        // printVector(p1_);

        // printVector(p2_);
        for(int i = 0; i < p1_.size(); ++i){
            TreeNode * cur = p1_[i];
            if(find(p2_.begin(), p2_.end(), cur) != p2_.end()){
                return cur;
            }
        }
        return nullptr;
    }

    void dfs(TreeNode* node, TreeNode*p, TreeNode* q){
        if(!node) return;
        path_.emplace_back(node);
        cout << node->val << endl;
        if(node == p){
            p1_ = path_;

        }else if(node == q){
            p2_ = path_;
        }
        dfs(node->left, p, q);
        dfs(node->right, p, q);
        path_.pop_back();
        return;
    
    }
};
