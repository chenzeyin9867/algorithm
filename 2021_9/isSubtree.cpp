#include "head.h"
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return dfs(root, subRoot);
    }

    bool isSameTree(TreeNode * node1, TreeNode* node2){
        if(!node1 && !node2) return true;
        if(!node1 || !node2) return false;
        if(node1->val != node2->val) return false;
        return (isSameTree(node1->left, node2->left) && isSameTree(node1->right, node2->right));
        
    }

    bool dfs(TreeNode* root, TreeNode* subroot){
        if(!root && !subroot) return true;
        if(!root || !subroot) return false;
        if(isSameTree(root, subroot) || dfs(root->left, subroot) || dfs(root->right, subroot) ) return true;
        return false;
    }
};