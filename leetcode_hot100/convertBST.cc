#include "head.h"
/* Covert a BST to a greater sum tree */
// class Solution {
// public:
//     unordered_map<TreeNode *, int> old_map;
//     TreeNode* convertBST(TreeNode* root) {
//         dfs(root); // Get the val for each node
//         update_node(root); // Update the val for each node
//         return root;
//     }

//     void dfs(TreeNode *node){
//         if(!node) return;
//         old_map[node] = node->val;
//         dfs(node->left);
//         dfs(node->right);
//         return;
//     }

//     void update_node(TreeNode *node){
//         if(!node) return;
//         //for each node, got the sum for all the val greater than it
//         int sum = 0;
//         for(auto &p : old_map){
//             if(p.second >= node->val){
//                 sum += p.second;
//             }
//         }
//         node->val = sum;
//         update_node(node->left);
//         update_node(node->right);
//         return;
//     }
// };

class Solution {
public:
    /*  Notice the feature of the BST that all its right childs greater
        than it, so we could dfs its right child first, then update 
        its value and its left child */
    int m_sum_;
    TreeNode* convertBST(TreeNode* root) {
        if(!root) return;
        convertBST(root->right);
        m_sum_ += root->val;
        root->val = m_sum_;
        convertBST(root->left);
        return root;
    }
};