/**
 * @brief       isSymmetric.cpp
 * @author 		chenzeyin (chenzeyin9867@buaa.edu.cn)
 * @date		2021-12-22
 */
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
    TreeNode* mirror_tree(TreeNode* node){
        if(!node) return nullptr;
        TreeNode* left = mirror_tree(node->left);
        TreeNode* right = mirror_tree(node->right);
        node->left = right;
        node->right = left;
        return node;
    }

    bool is_same_tree(TreeNode* n1, TreeNode * n2){
        if(!n1 && !n2) return true;
        else if(!n1 || !n2) return false;
        if(n1->val != n2->val) return false;
        return is_same_tree(n1->left, n2->left) && is_same_tree(n1->right, n2->right);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        TreeNode* left_mirror = mirror_tree(root->left);
        return is_same_tree(left_mirror, root->right);
    }


};