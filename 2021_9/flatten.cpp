#include "head.h"
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};


class Solution {
public:
    Node* flatten(Node* head) {
        stack<Node*> stk;
        Node * cur = head;
        while(cur || !stk.empty()){
            // stk.push(cur);
            if(cur->child){
                // stk.push(cur->child);
                stk.push(cur);
                cur->child->prev = cur;
                cur = cur->child;
                
            }else if(cur->next){
                cur = cur->next;
            }else{
                if(stk.empty()) break;
                cout << cur->val << endl;
                Node* prev = stk.top();
                stk.pop();
                cur->next = prev->next;
                if(cur->next)
                    cur->next->prev = cur;
                prev->next = prev->child;
                if(cur->next)
                    cur = cur->next;
                else
                    cur = prev;
                prev->child = nullptr;
            }

        }
        return head;
    }
};