/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        reverse_tree(root);
        return root;
    }

    void reverse_tree(TreeNode* node){
        if(!node) return;
        swap(node->left, node->right);
        reverse_tree(node->left);
        reverse_tree(node->right);
        return;
    }
};