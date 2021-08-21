// include some necessary heads for convinient
#ifndef HEAD_H
#define HEAD_H

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <memory>
#include <algorithm>
#include <stack>
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


inline void printVector(vector<int> & v){
    for(auto i : v){
        cout << i << " ";
    }
    cout << endl;
}

#endif