#include "head.h"
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q2.emplace(x);
        while(!q1.empty()){
            int y = q1.front();
            q2.emplace(y);
            q1.pop();
        }
        swap(q1, q2);
        
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int r = q1.front();
        q1.pop();
        return r;
    }
    
    /** Get the top element. */
    int top() {
        return q1.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty();
    }
public:
    queue<int> q1;
    queue<int> q2;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */