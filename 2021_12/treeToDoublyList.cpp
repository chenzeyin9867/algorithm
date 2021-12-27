/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        Node* dummyHead = nullptr;
        stack<Node*> stk;
        Node* cur = root;
        Node *prev = nullptr;
        Node *tail = nullptr;
        if(!root) return nullptr;
        // stk.push(cur);
        while(cur || !stk.empty()){
            // push all its left child into stk
            while(cur){
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top();
            if(!dummyHead) dummyHead = cur;
            stk.pop();
            if(prev){
                prev->right = cur;
                cur->left = prev;
            }
            prev = cur;
            tail = cur;
            cur = cur->right;
        }
        tail->right = dummyHead;
        dummyHead->left = tail;
        return dummyHead;
    }
};