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
    TreeNode* Convert(TreeNode* pRootOfTree) {
        if(!pRootOfTree) return nullptr;
        TreeNode* prev = nullptr;
        TreeNode *head = nullptr;
        TreeNode *cur = pRootOfTree;
        dfs(cur, prev, head);
        return head;
    }
    
    void dfs(TreeNode* cur, TreeNode* &prev, TreeNode* &head){
        if(!cur) return;
        dfs(cur->left, prev, head);
        if(!head) head = cur;
        if(prev){
            prev->right = cur;
            cur->left = prev;
        }
        prev = cur;
        dfs(cur->right, prev, head);
        return;
    }
};