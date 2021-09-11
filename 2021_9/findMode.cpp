#include "head.h"
bool cmp(const pair<int, int> &p1, const pair<int, int> &p2){
    return p1.second > p2.second;
}
 
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        map<int, int> cnt;
        vector<int> result;

        dfs(root, cnt);
        vector<pair<int, int> > cntVector{cnt.begin(), cnt.end()};
        int max = -1;
        sort(cntVector.begin(), cntVector.end(), cmp);
        for(auto it : cntVector){
            if(it.second < max) break;
            max = it.second;
            result.emplace_back(it.first);
        }
        return result;
    }
    

    void dfs(TreeNode* node, map<int, int> & cnt){
        if(!node) return; 
        cnt[node->val]++;
        dfs(node->left, cnt);
        dfs(node->right, cnt);
    }
};