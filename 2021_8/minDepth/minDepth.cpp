
 //Definition for a binary tree node.
 #include <algorithm>
 #include <iostream>
 #include <memory>
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
    int minDepth(TreeNode* root) {
        int depth = 1;
        if (!root){
            return 0;
        }
        inorderTraversal(root, depth);
        return min_depth;
    }

    void inorderTraversal(TreeNode *node, int depth){
        if (!node->left && !node->right){ // leaf node
            min_depth = (depth) < min_depth ? (depth) : min_depth;
        
        }else{
            if (node->left) inorderTraversal(node->left, depth+1);
            if (node->right) inorderTraversal(node->right, depth+1);
        }
    }
private:
    int min_depth = 100000;
    
};

int main(){
    Solution s;
    shared_ptr<TreeNode> root = make_shared<TreeNode>(3, make_shared<TreeNode>(9).get(), make_shared<TreeNode>(20, make_shared<TreeNode>(15).get(), make_shared<TreeNode>(7).get()).get());
    TreeNode * root2 = new TreeNode(2, nullptr, new TreeNode(3, nullptr, new TreeNode(4, nullptr, new TreeNode(5, nullptr, new TreeNode(6)))));
    cout << "min depth:" << s.minDepth(root2) << endl; 
    return 0;
}