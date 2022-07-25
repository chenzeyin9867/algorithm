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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return dfs(root1, root2);
        // return root1;
    }

    TreeNode* dfs(TreeNode *node1, TreeNode *node2){
        if(!node1 && !node2){
            return nullptr;
        }
        if(!node1){
            return node2;
        }
        if(!node2){
            return node1;
        }

        node1->val += node2->val;
        node1->left = dfs(node1->left, node2->left);
        node1->right = dfs(node1->right, node2->right);
        return node1;
    }
};