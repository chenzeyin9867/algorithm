#include "head.h"
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        int prev = INT32_MIN;
        int cnt = 0;
        return inOrderTraverse(root, prev, cnt);
    }
    bool inOrderTraverse(TreeNode* node, int& prev, int& nodeCnt){
        if(!node) return true;
        bool b1 = inOrderTraverse(node->left, prev, nodeCnt);
        if(node->val <= prev && nodeCnt) {
            
            return false;
        }
        prev = node->val;
        ++nodeCnt;
        bool b2 = inOrderTraverse(node->right, prev, nodeCnt);
        return b1 & b2;
    }
};