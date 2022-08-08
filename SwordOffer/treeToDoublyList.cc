#include "basic_head.h"
/**
 *  Transfer a tree to a double list
 */

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

class Solution {
public:
    Node* m_head_{nullptr};
    Node* m_cur_{nullptr};
    Node* m_prev_{nullptr};
    Node* treeToDoublyList(Node* root) {
        dfs(root);
        return m_head_;
    }

    void dfs(Node* node){
        if(!node){
            return;
        }
        dfs(node->left);
        if(!m_head_){
            m_head_ = node;
            m_cur_ = node;
            m_prev_ = node;
        }else{
            m_cur_ = node;
            m_cur_->left = m_prev_;
            m_prev_->right = node;
            m_prev_ = m_cur_;
        }
        dfs(node->right);
    }
};