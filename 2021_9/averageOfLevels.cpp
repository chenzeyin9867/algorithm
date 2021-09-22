#include "head.h"
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode* > q;
        vector<double> result;
        if(!root) return result;
        TreeNode *cur = root;
        q.push(cur);
        while(!q.empty()){
            vector<TreeNode*> tmp;
            while(!q.empty()){
                tmp.emplace_back(q.front());
                q.pop();
            }
            double ave = 0.0;
            for(auto v: tmp){
                ave += v->val;
                if(v->left)
                    q.push(v->left);
                if(v->right)
                    q.push(v->right);
            }
            ave = ave / tmp.size();
            result.emplace_back(ave);
        }
        return result;
    }
};