#include "head.h"
class Solution {
public:
    int minDiff = INT32_MAX;
    int minDiffInBST(TreeNode* root) {
        vector<int> NodeList;
        inorderTraversal(root, NodeList);
        return minDiff;
    }

    void inorderTraversal(TreeNode* node, vector<int>& NodeList){
        if(!node) return;
        inorderTraversal(node->left, NodeList);
        if(NodeList.empty()){
            NodeList.emplace_back(node->val);
        }else{
            minDiff = min(abs(node->val - NodeList.back()), minDiff);
            NodeList.emplace_back(node->val);
        }
        inorderTraversal(node->right, NodeList);
    }
};