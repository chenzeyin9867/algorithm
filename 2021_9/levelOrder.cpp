#include "head.h"
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<TreeNode*> tmp;
            while(!q.empty()){
                tmp.emplace_back(q.front());
                q.pop();
            }
            vector<int> val;
            for(auto it: tmp){
                val.emplace_back(it->val);
                if(it->left) q.push(it->left);
                if(it->right) q.push(it->right);        
            }
            result.emplace_back(val);
        }
        return result;
    }
};