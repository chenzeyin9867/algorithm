#include "head.h"
class MinStack {
public:
    MinStack() {

    }
    
    void push(int val) {
        if(m_stack1.empty()){
            m_stack1.push(val);
            m_stack2.push(val);
            return;
        }
        m_stack1.push(val);
        m_stack2.push(std::min(val, m_stack2.top()));
        return;
    }
    
    void pop() {
        if(m_stack1.empty()) return;
        m_stack1.pop();
        m_stack2.pop();
    }
    
    int top() {
        return m_stack1.top();
    }
    
    int getMin() {
        return m_stack2.top();
    }

    std::stack<int> m_stack1;
    std::stack<int> m_stack2;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */