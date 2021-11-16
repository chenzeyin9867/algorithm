// include some necessary heads for convinient
#ifndef HEAD_H
#define HEAD_H

#include <math.h>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <memory>
#include <algorithm>
#include <stack>
#include <math.h>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <hash_set>
#include <hash_map>
#include <numeric>

using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
      ListNode(int x, ListNode* nxt): val(x), next(nxt) {}
};

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


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


// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};




template <class T>
inline void printVector(vector<T>  v){
    for(auto i : v){
        cout << i << " ";
    }
    cout << endl;
}

// template <class T>
//     void swap(T &x, T &y){
//         T temp;
//         temp = x;
//         x = y;
//         y = temp;
//     }

#endif