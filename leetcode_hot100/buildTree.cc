#include "head.h"
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

/**
 * @brief Build a Tree based on the inorder and preorder traversal
 *        preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
 *                  输出: [3,9,20,null,null,15,7]
 */
class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return recursiveBuildTree(preorder, 0, preorder.size() - 1,
                                  inorder, 0, inorder.size() - 1);
    }

    TreeNode *recursiveBuildTree(vector<int> &preorder, int l_1, int r_1,
                                 vector<int> &inorder, int l_2, int r_2)
    {
        if (l_1 > r_1)
            return nullptr;
        // if(l_1 == r_1){
        //     return new TreeNode(preorder[l_1]);
        // }
        /* Fetch the first node of preorder first as the root */
        TreeNode *root = new TreeNode(preorder[l_1]);

        /* Get the location of root's val in inorder list */
        int mid_idx = -1;
        for (int k = l_2; k <= r_2; ++k)
        {
            if (inorder[k] == preorder[l_1])
            {
                mid_idx = k;
                break;
            }
        }

        int len_l = mid_idx - l_2;
        int len_r = r_2 - l_2 - len_l;
        /* Recursive build the root's SubLeft Tree and Right Tree */
        root->left = recursiveBuildTree(preorder, l_1 + 1, l_1 + len_l,
                                        inorder, l_2, mid_idx - 1);
        root->right = recursiveBuildTree(preorder, l_1 + len_l + 1, r_1,
                                         inorder, mid_idx + 1, r_2);
        return root;
    }
};