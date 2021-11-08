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
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        iter_process(root);
        return;
    }

    // process current node and return the last node
    TreeNode* iter_process(TreeNode* node){
        // if(!node) return nullptr;
        if(!node->left && !node->right) return node;
        TreeNode *lhs, *rhs;
        if(node->left)
            lhs = iter_process(node->left);
        if(node->right)
            rhs = iter_process(node->right);
        if(node->left)
        {           
            TreeNode* tmp = node->right;
            node->right = node->left;
            node->left = nullptr;
            lhs->right = tmp;
        }
        if(rhs) return rhs;
        if(lhs) return lhs;
        return node;
        // TreeNode* temp = node->right;
        // node->right = node->left;
        // node->left  = nullptr;
        // TreeNode* rhs = iter_process(node->right);
    }
};

int main(){
    Solution s;
    TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)), new TreeNode(5, nullptr, new TreeNode(6)));
    s.flatten(root);
    TreeNode* ret = root;
    while(ret){
        cout << " ->" << ret->val;
        ret = ret->right;
    }
}