#include "head.h"
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/


//Iteration version
class Solution {
public:
    vector<int> preorder(Node* root) {
        stack<Node*> stk;
        vector<int> result;
        if(!root) return result;
        stk.emplace(root);
        // result.emplace_back(root->val);
        Node * cur = root;
        while(!stk.empty()){
            cur = stk.top();
            stk.pop();
            result.emplace_back(cur->val);
            for(auto itr = cur->children.rbegin(); itr != cur->children.rend(); itr++){
                stk.emplace(*itr);
                // result.emplace_back((*itr)->val);
            }
            
        }
        return result;
    }
};