/**
 * @file maxDepth.cpp
 * @author chenzeyin (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "head.h"

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


class Solution {
private:
    int length;
public:

    int maxDepth(Node* root) {
        if(!root)   return 0;
        length = 0;
        dfs(root, 1);     
        return length;
    }

    void dfs(Node* node, int len){
        if(!node) return;
        length = max(len + 1, length);
        for(const auto & c: node->children){
            dfs(c, len + 1);
        }
    }
};