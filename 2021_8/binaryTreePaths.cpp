#include "head.h"
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if(!root) return result;
        vector<int> tmp;
        dfs(root, tmp, result);
        return result;
    }

    void dfs(TreeNode* node, vector<int> tmp, vector<string> &r){
        if(!node->left && !node->right) { // leaf node
            // cout << tmp << endl;
            // r.emplace_back(tmp);
            tmp.push_back(node->val);
            r.push_back(orderOut(tmp));
        }else{
            tmp.push_back(node->val);
            if(node->left)
                dfs(node->left, tmp, r);
            if(node->right)
                dfs(node->right, tmp, r); 
        }
    }


    string orderOut(const vector<int> s){
        if(s.size() == 1) return to_string(s[0]);
        else{
            string t;
            for(int i = 0; i < s.size(); i++){
                t += to_string(s[i]);
                if(i < s.size() - 1) t += "->";
            }
            // cout << t << endl;
            return t;
        }
        
    }
};

int main(){
    Solution s;
    TreeNode* head = new TreeNode(1, new TreeNode(2, nullptr, new TreeNode(5)), new TreeNode(3));
    vector<string> r = s.binaryTreePaths(head);
    printVector(r);
    return 0;
}