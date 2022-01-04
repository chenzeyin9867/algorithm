#include "../head.h"
// class TreeNode {
// public:
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) :
//             val(x), left(NULL), right(NULL) {
//     }
//     TreeNode(int x, TreeNode* l, TreeNode* r):
//             val(x), left(l), right(r){

//             }
// };

class Solution {
public:
    char* Serialize(TreeNode *root) {    
        if(!root) 
        {
             char ret = '#';
            return &ret;
        }
        string str;
        queue<TreeNode*> q;
        TreeNode* cur = root;
        q.push(root);
        cout << "Begin Serilize" << endl;
        while(!q.empty()){
            cur = q.front();
            q.pop();
            if(cur){
                str.push_back(cur->val - 0 + '0');
                q.push(cur->left);
                q.push(cur->right);
            }else{
                str.push_back('#');
            }
        }
        cout << str << endl;
        char * s = (char*)malloc(str.size() * sizeof(char));
        strcpy(s, str.data());
        return s;
        
    }
    TreeNode* Deserialize(char *str) {
        int m_len = strlen(str);
        unordered_map<char, TreeNode*> m_map;
        if(m_len == 0) return nullptr;
        if(str[0] == '#') return nullptr;
        cout << str << endl;
        TreeNode *head = new TreeNode(str[0] - '0');
        cout << "Head:" << head->val << endl;
        cout << "str[0]" << str[0] << endl;
        TreeNode *prev, *cur;
        m_map[str[0]] = head;
        int l = 0, r = 1;
        prev = head;
        while(r < m_len){
            TreeNode *l_c, *r_c;
            if(str[r] == '#')
                l_c = nullptr;
            else l_c = new TreeNode(str[r] - '0');
            if(str[r+1] == '#') r_c = nullptr;
            else r_c = new TreeNode(str[r+1] - '0');
            m_map[str[r]] = l_c;
            m_map[str[r+1]] = r_c;
            prev->left = l_c;
            prev->right = r_c;
            r = r + 2;
            ++l;
            while(str[l] == '#'){
                ++l;
            }
            if(l < m_len){
                char t = str[l];    
                prev = m_map[t];
            }
            
            
        }
        return head;
        
    }
    
   
};

void dfs(TreeNode* cur){
    if(!cur){
        return;
    }
    cout << cur->val << "->";
    dfs(cur->left);
    dfs(cur->right);
}

int main(){
    Solution s;
    TreeNode* head = new TreeNode(1, new TreeNode(2), new TreeNode(3, new TreeNode(6), new TreeNode(7)));
    char* t = s.Serialize(head);
    TreeNode* r = s.Deserialize(t);
    dfs(r);
    return 0;
}