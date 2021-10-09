#include "head.h"
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.size() == 0) return nullptr;
        TreeNode* head = new TreeNode(postorder.back()); 
        int val = postorder.back();
        auto it = find(inorder.begin(), inorder.end(), val);
        vector<int> inorderLeft(inorder.begin(), it);
        vector<int> inorderRight(it + 1, inorder.end());
        int leftSize = inorderLeft.size();
        vector<int> postorderLeft(postorder.begin(), postorder.begin() + leftSize);
        vector<int> postorderRight(postorder.begin() + leftSize, postorder.end() - 1);
        head->left = buildTree(inorderLeft, postorderLeft);
        head->right = buildTree(inorderRight, postorderRight);
        return head;
    }
};