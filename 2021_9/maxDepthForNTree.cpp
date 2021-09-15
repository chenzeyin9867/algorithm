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

class Solution {
public:
    int dfs(Node* node){
        if(!node) return 0;
        if(node->children.empty()) return 1;
        int depth = -1;
        for(auto n : node->children){
            int d = dfs(n);
            if(d > depth){
                depth = d; 
            }
        }
        return depth + 1;
    }
    int maxDepth(Node* root) {
        if(!root) return 0;
        int depth = dfs(root);
        return depth;
    }
};