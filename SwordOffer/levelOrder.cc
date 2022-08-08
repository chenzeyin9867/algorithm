#include "basic_head.h"
/** 
 *  Output the tree in a apecific order, 0 level left to right, otherwise
 *  from right to left.
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        int left = 1;
        vector<vector<int>> result;
        queue<TreeNode*> q;
        if(!root) return result;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            vector<int> tmp;
            
            for(int i = 0; i < sz; ++i){
                TreeNode *cur = q.front();
                tmp.push_back(cur->val);
                q.pop();
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            if(left){
                left = 0;
            }else{
                reverse(tmp.begin(), tmp.end());
                left = 1;
            }
            result.push_back(tmp);
        }
        return result;
    }
};