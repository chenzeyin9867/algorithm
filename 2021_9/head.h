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
#include <math.h>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <hash_set>
#include <hash_map>

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

template <class T>
inline void printVector(vector<T> & v){
    for(auto i : v){
        cout << i << " ";
    }
    cout << endl;
}

template <class T>
    void swap(T &x, T &y){
        T temp;
        temp = x;
        x = y;
        y = temp;
    }

#endif