#include "head.h"

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while(!stk1.empty()){
            int s = stk1.top();
            stk2.emplace(s);
            stk1.pop();
        }
        stk1.emplace(x);
        while(!stk2.empty()){
            int s =  stk2.top();
            stk1.emplace(s);
            stk2.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int s = stk1.top();
        stk1.pop();
        return s;

    }
    
    /** Get the front element. */
    int peek() {
        return stk1.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stk1.empty();
    }

public:
    stack<int> stk1;
    stack<int> stk2;        

};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */