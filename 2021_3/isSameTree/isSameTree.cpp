/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <iostream>
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if((!p && q) || (p && !q)){
            return false;
        }  
        if(!p && !q) return true;
        else{
            if(p->val == q->val) return isSameTree(p->left, q->left) & isSameTree(p->right, q->right);
            else{
                return false;
            }
        }
    }
};
int main(){
    Solution s;
    TreeNode * p = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    TreeNode * q = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    cout << s.isSameTree(p, q) << endl;
    return 0;
}