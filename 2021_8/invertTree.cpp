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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        // TreeNode* tmp = root->left;
        root->left = right;
        root->right = left;
        return root;
    }
};

void preTraversal(TreeNode* node){
    if(!node) return ;
    if(node) cout << node->val << endl;;
    preTraversal(node->left);
    preTraversal(node->right);
}

int main(){
    Solution s;
    TreeNode* head = new TreeNode(4, new TreeNode(2, new TreeNode(1), new TreeNode(3)), new TreeNode(7, new TreeNode(6), new TreeNode(9)));
    head = s.invertTree(head);
    cout << "Begin Traver" << endl;
    preTraversal(head);
    return 0;
}