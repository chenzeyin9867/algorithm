#include <iostream>
#include "../treenode.h"
using namespace std;


class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        return subPath(root, targetSum, 0);
    }

    bool subPath(TreeNode * root, int targetSum, int curNum){
        if(!root->left && !root->right){
            if(root->val == targetSum - curNum) return true;
            else return false;
        }
        if (root->left){
            if(subPath(root->left, targetSum, curNum + root->val)){
                return true;
            }
        } 
        if(root->right && subPath(root->right, targetSum, curNum + root->val)){
            return true;
        }
        return false;

    }
};

int main(){
    Solution s;
    TreeNode * t = new TreeNode(5, new TreeNode(4, new TreeNode(11, new TreeNode(7), new TreeNode(2)), nullptr), new TreeNode(8, new TreeNode(13), new TreeNode(4, nullptr, new TreeNode(1))));
    cout << s.hasPathSum(t, 22) << endl;
    return 0;

}