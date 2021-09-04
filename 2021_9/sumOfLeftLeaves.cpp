#include "head.h"
enum{ 
    LEFT = 1,RIGHT = 2   
    };

void preOrderTraverse(TreeNode* node, int type, int & sum){
    if(!node->left && !node->right && type == LEFT){
        sum += node->val;
    } 
    if(node->left){
        preOrderTraverse(node->left, LEFT, sum);
    }
    if(node->right){
        preOrderTraverse(node->right, RIGHT, sum);
    }
}

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {

        if(!root) return 0;
        if(!root->left && !root->right) return 0;
        int sum = 0;
        if (root->left){
            preOrderTraverse(root->left, LEFT, sum);
        }
        if (root->right){
            preOrderTraverse(root->right, RIGHT, sum);
        }
        return sum;
    }
};

