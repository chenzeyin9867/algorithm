#include "head.h"
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // first using the first num in preorder as the root 
        if(preorder.size() == 0) return nullptr;
        if(preorder.size() == 1) return new TreeNode(preorder.back());
        TreeNode* head = new TreeNode(preorder[0]);
        cout << "cur: " << head->val << endl;
        auto it = find(inorder.begin(), inorder.end(), head->val);
        vector<int> inorderLeft(inorder.begin(), it);
        vector<int> inorderRight(it + 1, inorder.end());
        int lenL = inorderLeft.size();
        int lenR = inorderRight.size();
        vector<int> preorderLeft(preorder.begin() + 1, preorder.begin() + 1 + lenL);
        vector<int> preorderRight(preorder.begin() + 1 + lenL, preorder.end());
        head->left = buildTree(preorderLeft, inorderLeft);
        head->right = buildTree(preorderRight, inorderRight);
        cout << "return head:" << head->val << endl;
        return head;
    }
};

void dfs(TreeNode* node){
    if(!node) return;
    cout << node->val << " ->";
    dfs(node->left);
    dfs(node->right);
}

int main(){
    Solution s;
    vector<int> v1 = {3,9,20,15,7};
    vector<int> v2 = {9,3,15,20,7};
    TreeNode* ret = s.buildTree(v1, v2);
    dfs(ret);
    return 0;
}