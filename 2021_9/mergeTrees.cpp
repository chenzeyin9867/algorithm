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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode* head;
        if(!root1 && !root2) return nullptr;
        if(!root1) return root2;
        if(!root2) return root1;
        dfs(root1, root2);
        return root1;
    }
    void dfs(TreeNode* node1, TreeNode* node2){
        if(!node2) return;
        node1->val += node2->val;
        if(node2->left){
            if(node1->left){
                dfs(node1->left, node2->left);
            }else{
                node1->left = node2->left;
            }
        } 
        if(node2->right){
            if(node1->right){
                dfs(node1->right, node2->right);
            }else{
                node1->right = node2->right;
            }
        }
    }
};