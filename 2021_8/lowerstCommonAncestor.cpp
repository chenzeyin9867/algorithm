/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include "head.h"
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q) return root;
        vector<TreeNode*> pathl = lookForPath(root, p);
        vector<TreeNode*> pathr = lookForPath(root, q); 
        TreeNode* ancestor;
        for(int i = 0; i < min(pathl.size(), pathr.size()); i++){
            if(pathl[i] == pathr[i])
                ancestor = pathl[i];
        }
        return ancestor;
    }

    vector<TreeNode*> lookForPath(TreeNode* root, TreeNode* node){
        vector<TreeNode*> rt;
        rt.emplace_back(root);
        while(root != node){
            if(node->val < root->val){
                root = root->left;
                rt.emplace_back(root);
            }else{
                root = root->right;
                rt.emplace_back(root);
            }
        }
        return rt;
    }
};