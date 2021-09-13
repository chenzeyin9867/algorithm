#include "head.h"
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        // InorderTraversal returns an ordered list
        int minidiff = 10000;
        int prev = -1;
        inorderTraverse(root, prev, minidiff);
        return minidiff;
    }

    void inorderTraverse(TreeNode* node, int &prevValue, int &min){
       if(node->left){
            inorderTraverse(node->left, prevValue, min);
        }
       if(prevValue>=0){
            min = abs(node->val - prevValue) < min ? abs(node->val - prevValue) : min;
            prevValue = node->val;
        }else{
            prevValue = node->val;
            
        }
        // cout << prevValue << endl;
        if(node->right){
            inorderTraverse(node->right, prevValue, min);
        }
    }
};

int main(){
    Solution s;
    TreeNode* head = new TreeNode(5, new TreeNode(4), new TreeNode(7));
    cout << s.getMinimumDifference(head) << endl;
    return 0;
}