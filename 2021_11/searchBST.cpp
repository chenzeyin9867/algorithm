/**
 * @file		searchBST.cpp
 * @brief       return the tree root
 * @author 		chenzeyin (chenzeyin9867@buaa.edu.cn)
 * @date		2021-11-26
 * @copyright	Copyright (c) 2021  chenzeyin9867
 */
#include "head.h"
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root->val == val) return root;
        TreeNode* cur = root;
        while(cur && cur->val != val){
            if(cur->val > val){
                cur = cur->left;
            }else{
                cur = cur->right;
            }
        }
        return cur;
    }
};