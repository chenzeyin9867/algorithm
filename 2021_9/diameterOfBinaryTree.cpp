#include "head.h"
class Node{
    public:
    Node(TreeNode* n, int _l, int _r): node(n), l(_l), r(_r){

    }
    TreeNode* node;
    int l;
    int r; 
};

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        vector<Node*> treeNodeLRLength; // A data structure to store the left and right treeNode lenght
        if(!root) return 0;
        int height = 0;
        int h = dfs(root, treeNodeLRLength);
        int maxTrajectory = 0;
        for(auto x: treeNodeLRLength){
            int tmp = x->l + x->r;
            maxTrajectory = tmp > maxTrajectory ? tmp : maxTrajectory;
        }
        return maxTrajectory;
    }
    
    int dfs(TreeNode* node, vector<Node*>& treeNodeLRLength){
        if(!node){
            return 0;
        }
        int lheight = dfs(node->left, treeNodeLRLength);    
        int rheight = dfs(node->right, treeNodeLRLength);
        treeNodeLRLength.emplace_back(new Node(node, lheight, rheight)); 
        return lheight > rheight ? lheight +1 : rheight + 1;      
    }
};