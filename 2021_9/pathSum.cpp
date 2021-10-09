#include "head.h"
class Solution {
public:
    int sum = 0;
    vector<vector<int>> result;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int cur = 0;
        vector<int> path;
        if(!root) return result;
        dfs(root, cur, path, targetSum);

        return result;

    }

    void dfs(TreeNode* node, int &cur, vector<int>& path,  int target){
        cur += node->val;
        path.emplace_back(node->val);
        if(!node->left && !node->right){
            // leaf node;
            if(cur == target){
                result.emplace_back(path);
            }
        }
        if(node->left){
            dfs(node->left, cur, path, target);
        }
        if(node->right){
            dfs(node->right, cur, path, target);
        }
        path.pop_back();
        cur -= node->val;
    }
};