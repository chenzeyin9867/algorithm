#include "head.h"
#include "treenode.h"
class Solution {
public:
    // Using stack-based 
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if(!root) return result;
        stack<TreeNode*> stk;
        stk.emplace(root);
        TreeNode * node = root;
        while(!stk.empty() && node){
            if(node->left){
                stk.emplace(node->left);
                node = stk.top();
            }
            if(node->right){
                stk.emplace(node->right);
                
            }else{
                cout << node->val << " ";
                result.emplace_back(node->val);
                stk.pop();
            }

        }
        return result;
        
    }
};

int main(){
    Solution s;
    TreeNode * root = new TreeNode(1, NULL, new TreeNode(2, new TreeNode(3), NULL));
    vector<int> r = s.postorderTraversal(root);
    printVector(r);
    return 0;
}