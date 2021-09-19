//  *? Definition for a binary tree node.
#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    string tree2str(TreeNode* root) {
        string result = "";
        preorderTraverse(root, result);
        return result;
        
    }

    void preorderTraverse(TreeNode* node, string& str){
        // if(!node) return;
        str+=(to_string(node->val));
        if(node->left || node->right){
            str.push_back('(');
            if(node->left)
                preorderTraverse(node->left, str);
            str.push_back(')');
        }

        if(node->right){
            str.push_back('(');
            preorderTraverse(node->right, str);
            str.push_back(')');
        }
        return ;
    }
};