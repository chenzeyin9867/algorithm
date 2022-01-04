/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<vector<int>> m_ret;
    int m_sum = 0;
    int m_exp;
    vector<int> m_vec;
    vector<vector<int>> FindPath(TreeNode* root,int expectNumber) {
        if(!root) return m_ret;
        m_exp = expectNumber;
        dfs(root);
        return m_ret;
    }
    
    void dfs(TreeNode* cur){
        if(!cur){
            return;
        }
        m_vec.push_back(cur->val);
        m_sum += cur->val;
        if(!cur->left && !cur->right){
            if(m_sum == m_exp){
                m_ret.push_back(m_vec);
            }            
        }
        dfs(cur->left);
        dfs(cur->right);
        m_sum -= cur->val;
        m_vec.pop_back();
    }
};