/**
 * @brief Using Monotone stack Algorithm
 */
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        stk.push(x);
        if(mono_stk.empty() || mono_stk.top() >= x){
            mono_stk.push(x);
        }
    }
    
    void pop() {
        // stk.pop();
        if(mono_stk.top() == stk.top()){
            mono_stk.pop();
        }
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int min() {
        return mono_stk.top();
    }

    stack<int> stk;
    stack<int> mono_stk;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */