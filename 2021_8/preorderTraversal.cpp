#include "head.h"
#include "treenode.h"
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector <int> result;
        preorder(root, result);
        return result;
        
    }

    void preorder(TreeNode* root, vector<int>&r){
        if(!root) return;
        else{
            r.push_back(root->val);
            preorder(root->left, r);
            preorder(root->right, r);
        }
    }
};

int main(){
    Solution s;
    TreeNode* head = new TreeNode(1, nullptr, new TreeNode(2, new TreeNode(3), NULL));
    vector<int> r = s.preorderTraversal(head);
    for(auto i : r){
        cout << i << " " ;
    }
    cout << endl;
    return 0;
}